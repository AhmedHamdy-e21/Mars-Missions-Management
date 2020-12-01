
#include <iostream>
#include "Mission related/Mission.h"
#include "Rover related/Rover.h"
#include "Queue/LinkedQueue.h"
#include "RoverList.h"
#include "MissionList.h"

#include <fstream>
#include <string>
using namespace std;
template<typename T>
void SameOrder(LinkedQueue <T> Q, LinkedQueue<T> Q1) {
    T x, y;
    while (!Q.isEmpty() && !Q1.isEmpty())
    {
        Q1.dequeue(x);
        Q.dequeue(y);
        if ((Q.isEmpty() && !Q1.isEmpty()) || (!Q.isEmpty() && Q1.isEmpty()))
        {
            cout << "\n\nThis Stack and this Queue are not of the Same Order\n";
            return;
        }
        if (x == y) {

        }
        else
        {
            cout << "\n\n This Stack and this Queue are not of the Same Order\n";
            return;
        }
    }
    cout << "\n\nThis Stack and this Queue are of the Same Order\n";
}
void loadFile(RoverList& RL,MissionList& ML,LinkedQueue<Mission>& CurrentE,LinkedQueue<Mission> & CurrentM,LinkedQueue<Mission> &CurrentP) {
    ifstream inputFile;

    inputFile.open("Input Sample.txt");
    // Check for Error:
    if (inputFile.fail()) {
        cerr << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "All is good" << endl;
    }
    int M,P,E,SM,SP,SE,N,CM,CP,CE,AutoP,EV,ED,ID,TLOC,MIDUR,SIG;
    char F,TYP;

    inputFile >> M;

    inputFile >> P;
    inputFile >> E;
    inputFile >> SM;
    inputFile >> SP;
    inputFile >> SE;
    inputFile >> N;
    inputFile >> CM;
    inputFile >> CP;
    inputFile >> CE;
    inputFile >> AutoP;
    RL.setERoverList(E,SE,CE);
    RL.setMRoverList(M,SM,CM);
    RL.setPRoverList(P,SP,CP);

    inputFile >> EV;
    ML.setMissionList(EV);
    for (int j = 0; j < EV; j++)
    {
        string type;
        inputFile >> type;
        if (type == "F")
        {
            inputFile >> TYP;
            inputFile>> ED;
            inputFile>> ID;
            inputFile>> TLOC;
            inputFile>> MIDUR;
            inputFile>> SIG;

            ML.AddMission(ED,ID,TLOC,MIDUR,SIG,TYP);

        }

        else if (type == "X")
        {
            inputFile>> ED;
            inputFile>> ID;
            ML.CancelMission(ED,ID,CurrentE,CurrentM,CurrentP);;

        }
        else if (type == "P")
        {
            inputFile>> ED;
            inputFile>> ID;
            ML.PromoteMission(ED,ID);
        }
    }


    inputFile.close();

}


// This will be eliminated when implementing this array using linkedlist
#define MAX_size 100

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
    cout<<"Current Day:   "<<Day<<endl;
}

int main() {
    ////Initializations
    RoverList RL;

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
            printInteractiveMode(Day);
            Interactive(AvailableEQueue,CurrentE);
        }
        Day++;
    }


    return 0;
}

void Interactive(LinkedQueue<struct Rover> queue, LinkedQueue<struct Mission> queue1) {

}



