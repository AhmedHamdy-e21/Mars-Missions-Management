//
// Created by raspberry on 2020-11-24.
//

#include "MarsStation.h"


void MarsStation::loadFile()
{
    ifstream inputFile;

    inputFile.open("../Input Sample.txt");
    
    if (inputFile.fail()) {
        cerr << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "All is good" << endl;
    }
    int M, P, E, SM, SP, SE, N, CM, CP, CE, EV, ED, ID, TLOC, MIDUR, SIG;
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
    RL = RoverList(
        M, P, E, SM, SP, SE, CM, CP, CE, N
    );

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
    bool x = ML.getEQueue().isEmpty();
    bool y = ML.getPQueue().isEmpty();
    bool z = ML.getMQueue().isEmpty();
    return x && y && z && Formaulation_Event.isEmpty();
}


void MarsStation::CancelMission(int id)
{
    ML.CancelMission(id);
}

void MarsStation::PromoteMission(int id)
{
    ML.PromoteMission(id);
}

 void MarsStation::AssignMissions(int Day){
    LinkedQueue<Mission> EMList, MMList, PMList;
    LinkedQueue<Rover*> ERList, MRList, PRList;
    ML.getCurrentDayMissions(Day, EMList, PMList, MMList, AutoP);
    MRList = RL.getAvailableMQueue(Day);
    ERList = RL.getAvailableEQueue(Day);
    PRList = RL.getAvailablePQueue(Day);

    Mission tmpM;
    while (EMList.peek(tmpM)) {
        Rover* tmpR;
        if (ERList.peek(tmpR)) {
            EMList.dequeue(tmpM);
            ERList.dequeue(tmpR);
            tmpR->getAssigned(tmpM.getED(), tmpM.getMissionDuration());
            ML.changeStateByID(tmpM.getID(), Executing);
            ML.changeCDByID(tmpM.getID(), Day + tmpM.getMissionDuration());
        }
        else if (MRList.peek(tmpR)) {
            EMList.dequeue(tmpM);
            MRList.dequeue(tmpR);
            tmpR->getAssigned(tmpM.getED(), tmpM.getMissionDuration());
            ML.changeStateByID(tmpM.getID(), Executing);
            ML.changeCDByID(tmpM.getID(), Day + tmpM.getMissionDuration());
        }
        else if (PRList.peek(tmpR)) {
            EMList.dequeue(tmpM);
            PRList.dequeue(tmpR);
            tmpR->getAssigned(tmpM.getED(), tmpM.getMissionDuration());
            ML.changeStateByID(tmpM.getID(),Executing);
            ML.changeCDByID(tmpM.getID(), Day + tmpM.getMissionDuration());
        }
        else break;
    }
    while (PMList.peek(tmpM)) {
        Rover* tmpR;
        if (PRList.peek(tmpR)) {
            PMList.dequeue(tmpM);
            PRList.dequeue(tmpR);
            tmpR->getAssigned(tmpM.getED(), tmpM.getMissionDuration());
            ML.changeStateByID(tmpM.getID(), Executing);
            ML.changeCDByID(tmpM.getID(), Day + tmpM.getMissionDuration());
        }
        else break;
    }
    while (MMList.peek(tmpM)) {
        Rover* tmpR;
        if (MRList.peek(tmpR)) {
            MMList.dequeue(tmpM);
            MRList.dequeue(tmpR);
            tmpR->getAssigned(tmpM.getED(), tmpM.getMissionDuration());
            ML.changeStateByID(tmpM.getID(), Executing);
            ML.changeCDByID(tmpM.getID(), Day + tmpM.getMissionDuration());
        }
        else break;
    }

}


void MarsStation::Simulate(int Day)
{

        FormulationEvent F;
        int ID;
        Mission M;
        Mission E;
        Mission P;
        //int AvaliableM = 0, AvaliableE = 0, AvaliableP = 0;
        LinkedQueue<int> WaitingM, WaitingP, WaitingE;
        LinkedQueue<int> ExcutingM, ExcutingP,ExcutingE;
        LinkedQueue<int> CompletedM, CompletedP, CompletedE;

        int Mode;
        cout << "Enter The mode \n1- Interactive\n2-Silent\n3step_by-step\n";
        cin >> Mode;
        FormulationEvent fe;
        LinkedQueue<FormulationEvent> Formaulation_Event_bk;
        while (Formaulation_Event.peek(fe)) {
            Formaulation_Event.dequeue(fe);
            if (fe.get_event_day() == Day)
                fe.Execute();
            else Formaulation_Event_bk.enqueue(fe);
           
        }
        while (Formaulation_Event_bk.dequeue(fe)) {
            Formaulation_Event.enqueue(fe);
        }



        

        if (Mode == 1)
        {   
            AssignMissions(Day);
            LinkedQueue<Mission> EMList, MMList, PMList;
            ML.getAllMissions(EMList, PMList, MMList,Day);
            Mission m;
            while (EMList.dequeue(m)) {
                if (m.get_status() == Waiting) WaitingE.enqueue(m.getID());
                else if (m.get_status() == Executing) ExcutingE.enqueue(m.getID());
                else if (m.get_status() == Completed) CompletedE.enqueue(m.getID());
            }
            while (PMList.dequeue(m)) {
                if (m.get_status() == Waiting) WaitingP.enqueue(m.getID());
                else if (m.get_status() == Executing) ExcutingP.enqueue(m.getID());
                else if (m.get_status() == Completed) CompletedP.enqueue(m.getID());
            }
            while (MMList.dequeue(m)) {
                if (m.get_status() == Waiting) WaitingM.enqueue(m.getID());
                else if (m.get_status() == Executing) ExcutingM.enqueue(m.getID());
                else if (m.get_status() == Completed) CompletedM.enqueue(m.getID());
            }
            //AvaliableM = AvaliableRovers(AvailableMQueue, CurrentM);
            //AvaliableP = AvaliableRovers(AvailablePQueue, CurrentP);
            //AvaliableE = AvaliableRovers(AvailableEQueue, CurrentE);
           /* while (Formaulation_Event.dequeue(F)) //BUG! will need to be edited after we have completed & execution
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
            }*/
            

        }
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
