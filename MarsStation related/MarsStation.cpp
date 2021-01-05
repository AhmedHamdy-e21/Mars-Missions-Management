//
// Created by raspberry on 2020-11-24.
//

#include "MarsStation.h"


void MarsStation::loadFile()
{
    ifstream inputFile;

    inputFile.open("../Input Sample.txt");
    // Check for Error:
    if (inputFile.fail()) {
        cerr << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "All is good" << endl;
    }
    int M, P, E, SM, SP, SE, N, CM, CP, CE, AutoP, EV, ED, ID, TLOC, MIDUR, SIG;
    char F, TYP;

    inputFile >> M;

    inputFile >> P;
    inputFile >> E; //number of events
    inputFile >> SM; 
    inputFile >> SP;
    inputFile >> SE;
    inputFile >> N;
    inputFile >> CM;
    inputFile >> CP;
    inputFile >> CE;
    inputFile >> AutoP;
    RL.setERoverList(E, SE, CE);
    RL.setMRoverList(M, SM, CM);
    RL.setPRoverList(P, SP, CP);

    inputFile >> EV;
    ML.setMissionList(EV);
    for (int j = 0; j < EV; j++)
    {
        string type;
        inputFile >> type;
        if (type == "F")
        {
      
            inputFile >> TYP;
            inputFile >> ED;
            inputFile >> ID;
            inputFile >> TLOC;
            inputFile >> MIDUR;
            inputFile >> SIG;
            FormulationEvent F_event = FormulationEvent(TYP, TLOC, MIDUR, SIG, ED, ID, &ML, &RL);
            Events.enqueue(F_event);
            Formaulation_Event.enqueue(F_event);

          //  ML.AddMission(ED, ID, TLOC, MIDUR, SIG, TYP);

        }

        else if (type == "X")
        {

            inputFile >> ED;
            inputFile >> ID;

            CancelEvent C_event = CancelEvent(ED, ID, &ML, &RL);
            Events.enqueue(C_event);
           // ML.CancelMission(ED, ID, CurrentE, CurrentM, CurrentP);;

        }
        else if (type == "P")
        {
            inputFile >> ED;
            inputFile >> ID;

            PromoteEvent P_event = PromoteEvent(ED, ID,&ML,&RL);
            Events.enqueue(P_event);
            //ML.PromoteMission(ED, ID);
        }
    }


    inputFile.close();

    // Testing Event output (OMNIA) 
    
   /* while (!Events.isEmpty()) {
        Event E;
        Events.dequeue(E);
        cout << "Event day" << E.get_event_day() << endl;
        cout <<"Event type" << E.get_event_type() << endl;
        cout << "Mission ID:" <<E.get_Mission_ID() << endl;
    }
    */
    

   
}

MarsStation::MarsStation()
{
    ML = MissionList();
    RL = RoverList();
}

bool MarsStation::Must_Stop()
{
    return ML.isEmpty();
}

inline int MarsStation::AvaliableRovers(LinkedQueue<Rover> rovers, LinkedQueue<Mission> missions)
{
    Rover R;
    Mission M;
    bool QboolR, QboolM;
    int AvliableRovers;
    QboolR = rovers.dequeue(R);
    QboolM = missions.dequeue(M);
    while (QboolM || QboolR) {

        if (!QboolM && QboolR) {
           /* waitinglistmissions[j] = Missions;
            j = j + 1;*/

            QboolM = missions.dequeue(M);
        
        }
        else if (QboolM && !QboolR) {
          /*  waitinglistrovers[y] = Rovers;
            y = y + 1;*/
            QboolR = rovers.dequeue(R);
            AvliableRovers = M.getID();
            return AvliableRovers;
        }
        else if (QboolM && QboolR) {
           /* Executionlistmissions[i] = Missions;
            Executionlistrovers[x] = Rovers;
            i = i + 1;
            x = x + 1;*/
            QboolR = rovers.dequeue(R);
            QboolM = missions.dequeue(M);
        }
        else {
            break;
        }
    }
    
}


void MarsStation::Simulate(int Day)
{
        //loadFile(); // ya teb2a hena ya fil main 
        FormulationEvent F;
        int ID;
        Mission M;
        Mission E;
        Mission P;
        int AvaliableM = 0, AvaliableE = 0, AvaliableP = 0;
        LinkedQueue<int> WaitingM, WaitingP, WaitingE;
        LinkedQueue<int> ExcutingM, ExcutingP,ExcutingE;
        LinkedQueue<int> CompletedM, CompletedP, CompletedE;
        ML.getCurrentDayMissions(Day, CurrentE, CurrentM, CurrentP);
        int Mode;
        cout << "Enter The mode \n1- Interactive\n2-Silent\n3step_by-step\n";
        cin >> Mode;
        FormulationEvent fe;
        LinkedQueue<FormulationEvent> Formaulation_Event_bk;

        while (Formaulation_Event.dequeue(fe)) {
            fe.Execute(); 
            Formaulation_Event_bk.enqueue(fe);
        }
        while (Formaulation_Event_bk.dequeue(fe)) {
            Formaulation_Event.enqueue(fe);
        }
        AvailableMQueue = RL.getAvailableMQueue();
        AvailableEQueue = RL.getAvailableEQueue();
        AvailablePQueue = RL.getAvailablePQueue();
        CurrentE = ML.getEQueue();  
        CurrentP = ML.getPQueue();
        CurrentM = ML.getMQueue();
        if (Mode == 1)
        {   
            AvaliableM = AvaliableRovers(AvailableMQueue, CurrentM);
            AvaliableP = AvaliableRovers(AvailablePQueue, CurrentP);
            AvaliableE = AvaliableRovers(AvailableEQueue, CurrentE);
            while (Formaulation_Event.dequeue(F)) //BUG! will need to be edited after we have completed & execution
            {


                
                CurrentM.peek(M);
                if (F.get_Mission_ID() == M.getID()) {
                    CurrentM.dequeue(M);
                    if (M.get_status() == 0) {
                        WaitingM.enqueue(F.get_Mission_ID());
                    }
                    else if (M.get_status() == 1) {
                        ExcutingM.enqueue(F.get_Mission_ID());
                    }
                    else if (M.get_status() == 2)
                    {
                        CompletedM.enqueue(F.get_Mission_ID());
                    }
                }
                CurrentE.peek(E);
                if (F.get_Mission_ID() == E.getID()) {
                    CurrentE.dequeue(E);
                    if (E.get_status() == 0) {
                        WaitingE.enqueue(F.get_Mission_ID());
                    }
                    else if (E.get_status() == 1) {
                        ExcutingE.enqueue(F.get_Mission_ID());
                    }
                    else if (E.get_status() == 2)
                    {
                        CompletedE.enqueue(F.get_Mission_ID());
                    }
                }
                CurrentP.peek(P);
                if (F.get_Mission_ID() == P.getID())  {
                    CurrentP.dequeue(P);
                    if (P.get_status() == 0) {
                        WaitingP.enqueue(F.get_Mission_ID());
                    }

                    else if (P.get_status() == 1) {
                        ExcutingP.enqueue(F.get_Mission_ID());
                    }
                    else if (P.get_status() == 2)
                    {
                        CompletedP.enqueue(F.get_Mission_ID());
                    }
                }
            }
            

        }

        Day++;
        int id1 = 0, id2 =0 , id3 =0;
        cout << "\nWaiting Missions: ";
        bool e = WaitingE.dequeue(id1);
        bool m = WaitingM.dequeue(id2);
        bool p = WaitingP.dequeue(id3);
        while (e || m || p )
        {
            if (e)
                cout << "[" <<id1 << "]";
            if (m)
                cout <<" "<<id2<< " ";
            if(p)
                cout << "(" << id3 <<")";

             e = WaitingE.dequeue(id1);
             m = WaitingM.dequeue(id2);
             p = WaitingP.dequeue(id3);
        } 
        cout << "\nExcuting Missions: ";

        e = ExcutingE.dequeue(id1);
        m = ExcutingM.dequeue(id2);
        p = ExcutingP.dequeue(id3);
        while (e || m || p)
        {
            if (e)
                cout << "[" << id1 << "]";
            if (m)
                cout << " " << id2 << " ";
            if (p)
                cout << "(" << id3 << ")";

            e = ExcutingE.dequeue(id1);
            m = ExcutingM.dequeue(id2);
            p = ExcutingP.dequeue(id3);

        } 
        cout << "\nCompleted Missions: ";

        e = CompletedE.dequeue(id1);
        m = CompletedM.dequeue(id2);
        p = CompletedP.dequeue(id3);
        while (e || m || p)
        {
            if (e)
                cout << "[" << id1 << "]";
            if (m)
                cout << " " << id2 << " ";
            if (p)
                cout << "(" << id3 << ")";

            e= CompletedE.dequeue(id1);
            m = CompletedM.dequeue(id2);
            p = CompletedP.dequeue(id3);
        }
            
}
