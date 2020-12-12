
#include <iostream>
#include "Mission related/Mission.h"
#include "Rover related/Rover.h"
#include "Queue/LinkedQueue.h"
#include "MarsStation related/RoverList.h"
#include "MarsStation related/MissionList.h"
#include"MarsStation related/MarsStation.h"


using namespace std;


// This will be eliminated when implementing this array using linkedlist
/*#define MAX_size 100

void Interactive(LinkedQueue<struct Rover> queue, LinkedQueue<struct Mission> queue1);

template<typename T>
void Interactive(LinkedQueue<T> rovers, LinkedQueue<T> missions) {
    T Rovers, Missions;
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    bool Qbool1, Q2bool;
    int waitinglistmissions[MAX_size];
    int waitinglistrovers[MAX_size];
    int Executionlistmissions[MAX_size];
    int Executionlistrovers[MAX_size];
    Qbool1 = rovers.dequeue(Rovers);
    Q2bool = missions.dequeue(Missions);
    while (Qbool1 || Q2bool) {

        if (!Qbool1 && Q2bool) {
            waitinglistmissions[j] = Missions;
            j = j + 1;

            Q2bool = missions.dequeue(Missions);
        } else if (Qbool1 && !Q2bool) {
            waitinglistrovers[y] = Rovers;
            y = y + 1;
            Qbool1 = rovers.dequeue(Rovers);

        } else if (Qbool1 && Q2bool) {
            Executionlistmissions[i] = Missions;
            Executionlistrovers[x] = Rovers;
            i = i + 1;
            x = x + 1;
            Qbool1 = rovers.dequeue(Rovers);
            Q2bool = missions.dequeue(Missions);
        } else {
            break;
        }
    }
}

    void printInteractiveMode(int Day)
{

    int Emergency, Mountain, Polar, currentday;
    cout << "Avaliable Rovers: " <<"( "<< Polar << " )  "<<"[ "<< Emergency<<" ]  "<< Mountain<<"  " <<endl;
    cout << "Waiting Missions: " << "( " << Polar << " )  " << "[ " << Emergency << " ]  " << Mountain << "  " << endl;
    cout << "In=Execution Missions: " << "( " << Polar << " )  " << "[ " << Emergency << " ]  " << Mountain << "  " << endl;
    cout << "Completed Missions: " << "( " << Polar << " )  " << "[ " << Emergency << " ]  " << Mountain << "  " << endl;
    cout<<"Current Day:   "<<Day<<endl;
    
}
*/

int main() {
    ////Initializations
    MarsStation Station = MarsStation();
    Station.loadFile();
    int Day_Counter = 1;
    while (!Station.Must_Stop()) {
        Station.Simulate(Day_Counter);
    }




    /*RoverList RL;

    MissionList ML;
   LinkedQueue<Mission> CurrentE;
   LinkedQueue<Mission> CurrentM;
   LinkedQueue<Mission> CurrentP;

    LinkedQueue<Rover> AvailableEQueue;
    LinkedQueue<Rover> AvailableMQueue;
    LinkedQueue<Rover> AvailablePQueue;


    int Day=5;

    //// Load function:

    loadFile(RL,ML,CurrentE,CurrentM,CurrentP);




    //// so we have all current missions in the three queues
    //// Get available missions into a lists CurrentE,CurrentM,CurrentP

    while (true)
    {
        //// Get today's missions;
        ML.getCurrentDayMissions(Day,CurrentE,CurrentM,CurrentP);
        int Mode;
        cout<<"Enter The mode \n1- Interactive\n2-Silent\n3step_by-step\n";
        cin>>Mode;
        ////Mission cancellation function
        AvailableEQueue=RL.getAvailableEQueue();
        if(Mode==1)
        {
            //// we need to get all needed values needed in the interactive mode just using the getters.
            //// Then pass these values in the Interactive print function.

            printInteractiveMode(Day);
            Interactive(AvailableEQueue,CurrentE);
        }
        Day++;
    }


    return 0;
    */
}

void Interactive(LinkedQueue<struct Rover> queue, LinkedQueue<struct Mission> queue1) {

}



