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
            FormulationEvent F_event = FormulationEvent(TYP, TLOC, MIDUR, SIG, ED, ID, ML, RL);
            Events.enqueue(F_event);
            Formaulation_Event.enqueue(F_event);

          //  ML.AddMission(ED, ID, TLOC, MIDUR, SIG, TYP);

        }

        else if (type == "X")
        {

            inputFile >> ED;
            inputFile >> ID;

            CancelEvent C_event = CancelEvent(ED, ID, ML, RL);
            Events.enqueue(C_event);
           // ML.CancelMission(ED, ID, CurrentE, CurrentM, CurrentP);;

        }
        else if (type == "P")
        {
            inputFile >> ED;
            inputFile >> ID;

            PromoteEvent P_event = PromoteEvent(ED, ID,ML,RL);
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
        loadFile();
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
        
        AvailableMQueue = RL.getAvailableMQueue();
        AvailableEQueue = RL.getAvailableEQueue();
        AvailablePQueue = RL.getAvailablePQueue();
        if (Mode == 1)
        {   
            AvaliableM = AvaliableRovers(AvailableMQueue, CurrentM);// kolo linked quueue
            AvaliableP = AvaliableRovers(AvailablePQueue, CurrentP);
            AvaliableE = AvaliableRovers(AvailableEQueue, CurrentE);
            while (Formaulation_Event.dequeue(F))
            {
                CurrentM.dequeue(M);
                CurrentE.dequeue(E);
                CurrentP.dequeue(P);

                if (M.get_status() == 0) {
                    WaitingM.enqueue(F.get_Mission_ID());
                }
                else if (M.get_status() == 1) {
                    ExcutingM.enqueue( F.get_Mission_ID());
                }
                else if (M.get_status() ==2 )
                { 
                    CompletedM.enqueue( F.get_Mission_ID());
                }
                if (E.get_status() == 0) {
                    WaitingE.enqueue( F.get_Mission_ID());
                }
                else if (E.get_status() == 1) {
                    ExcutingE.enqueue(F.get_Mission_ID());
                }
                else if (E.get_status() == 2)
                {
                    CompletedE.enqueue(F.get_Mission_ID());
                }
                if (P.get_status() == 0) {
                    WaitingP.enqueue( F.get_Mission_ID());
                }
                else if (P.get_status() == 1) {
                    ExcutingP.enqueue( F.get_Mission_ID());
                }
                else if (P.get_status() == 2)
                {
                    CompletedP.enqueue(F.get_Mission_ID());
                }
            }
            
            Formaulation_Event.dequeue(F);
        }

        Day++;
        cout << "\nWaiting Missions: ";
        while (WaitingE.dequeue(ID) && WaitingM.dequeue(ID) && WaitingP.dequeue(ID))
        {
            cout << WaitingM.peek(ID) << " ( " << WaitingP.peek(ID) << " )" << " [ " << WaitingE.peek(ID) << " ]";           
            WaitingE.dequeue(ID); WaitingM.dequeue(ID); WaitingP.dequeue(ID);
        } 
        cout << "\nExcuting Missions: ";
        while (ExcutingM.dequeue(ID) && ExcutingP.dequeue(ID) && ExcutingE.dequeue(ID))
        {
            cout << ExcutingM.peek(ID) << " ( " << ExcutingP.peek(ID) << " )" << " [ " << ExcutingE.peek(ID) << " ]";           
            ExcutingM.dequeue(ID); ExcutingE.dequeue(ID); ExcutingP.dequeue(ID);
        } cout << "\nCompleted Missions: ";
        while (CompletedM.dequeue(ID) && CompletedP.dequeue(ID) && CompletedE.dequeue(ID))
        {
            cout << CompletedM.peek(ID) << " ( " << CompletedP.peek(ID) << " )" << " [ " << CompletedE.peek(ID) << " ]";         
            CompletedM.dequeue(ID); CompletedE.dequeue(ID); CompletedP.dequeue(ID);
        }
            
}
