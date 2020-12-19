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

//template<typename T>
//inline void MarsStation::AvaliableRovers(LinkedQueue<Rover> rovers, LinkedQueue<Mission> missions)
//{
//    T Rovers;
//    T Missions;
//    int i = 0;
//    int j = 0;
//    int x = 0;
//    int y = 0;
//    bool Qbool1, Q2bool;
//    int waitinglistmissions[100];
//    int waitinglistrovers[100];
//    int Executionlistmissions[100];
//    int Executionlistrovers[100];
//    Qbool1 = rovers.dequeue(Rovers);
//    Q2bool = missions.dequeue(Missions);
//    Qbool1 = rovers.dequeue(Rovers);
//    Q2bool = missions.dequeue(Missions);
//    while (Qbool1 || Q2bool) {
//
//        if (!Qbool1 && Q2bool) {
//            waitinglistmissions[j] = Missions;
//            j = j + 1;
//
//            Q2bool = missions.dequeue(Missions);
//        }
//        else if (Qbool1 && !Q2bool) {
//            waitinglistrovers[y] = Rovers;
//            y = y + 1;
//            Qbool1 = rovers.dequeue(Rovers);
//
//        }
//        else if (Qbool1 && Q2bool) {
//            Executionlistmissions[i] = Missions;
//            Executionlistrovers[x] = Rovers;
//            i = i + 1;
//            x = x + 1;
//            Qbool1 = rovers.dequeue(Rovers);
//            Q2bool = missions.dequeue(Missions);
//        }
//        else {
//            break;
//        }
//    }
//}

void MarsStation::Simulate(int Day)
{
        loadFile();
        Event F;
        Mission M;
        Mission E;
        Mission P;
        int AvaliableM = 0, AvaliableE = 0, AvaliableP = 0;
        int WaitingM=0, WaitingP=0, WaitingE=0;
        int ExcutingM=0, ExcutingP=0,ExcutingE=0;
        int CompletedM=0, CompletedP=0, CompletedE=0;
        ML.getCurrentDayMissions(Day, CurrentE, CurrentM, CurrentP);
        int Mode;
        cout << "Enter The mode \n1- Interactive\n2-Silent\n3step_by-step\n";
        cin >> Mode;
        
        AvailableMQueue = RL.getAvailableMQueue();
        AvailableEQueue = RL.getAvailableEQueue();
        AvailablePQueue = RL.getAvailablePQueue();
        if (Mode == 1)
        {   
            AvaliableM = AvaliableRovers(AvailableMQueue, CurrentM);
            AvaliableP = AvaliableRovers(AvailablePQueue, CurrentP);
            AvaliableE = AvaliableRovers(AvailableEQueue, CurrentE);
            Events.dequeue(F);
            if (F.get_event_type()==0)
            {
                CurrentM.dequeue(M);
                CurrentE.dequeue(E);
                CurrentP.dequeue(P);
                if (M.get_status() == 0) {
                    WaitingM = F.get_Mission_ID();
                }
                else if (M.get_status() == 1) {
                    ExcutingM = F.get_Mission_ID();
                }
                else
                {
                    CompletedM = F.get_Mission_ID();
                }
                
                if (E.get_status() == 0) {
                    WaitingE = F.get_Mission_ID();
                }  
                else if (E.get_status() == 1) {
                    ExcutingE = F.get_Mission_ID();
                }
                else
                {
                    CompletedE = F.get_Mission_ID();
                }
                if (P.get_status() == 0) {
                    WaitingP = F.get_Mission_ID();
                }
                 else if (P.get_status() == 1) {
                    ExcutingP = F.get_Mission_ID();
                }
                else
                {
                    CompletedP = F.get_Mission_ID();
                }
            }
            
            cout << "Avaliable Rovers: " << AvaliableM << " ( " << AvaliableP << " )" << " [ " << AvaliableE << " ]" << endl;
            cout << "Waiting Missions: " << WaitingM << " ( " <<WaitingP <<" )"<<" [ "<< WaitingE<<" ]"<< endl;
            cout << "Executing Missions: " << ExcutingM << " ( " <<ExcutingP <<" )"<<" [ "<< ExcutingE<<" ]"<< endl;
            cout << "Completed Missions: " << CompletedM << " ( " <<CompletedP <<" )"<<" [ "<< CompletedE<<" ]"<< endl;

           
        }
        Day++;
    
}
