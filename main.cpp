#include <iostream>
#include "Mission.h"
#include "Rover.h"
#include "Queue/LinkedQueue.h"
#include "BSTree/BSTree.h"
#include "RoverList.h"
#include "MissionList.h"

using namespace std;



void initializeRover(int NoOfRover);

void ReadFile();

int main() {
    int DayRefresh=0;

    int NoofM=3;
    int NoofP=3;
    int NoofE=2;


    int SpeedM=1;
    int SpeedP=2;
    int SpeedE=2;

    int NoOFMissions=3;
    int CheckupDurationM=9;
    int CheckupDurationP=8;
    int CheckupDurationE=7;

    int AutoP=25;

//    int Noevent=8;
    char F='F';
    char M='M';
    int EventDay=2;
    int ID=1;
    int TargetLocation=100;
    int MissionRequirementDuration=4;
    int Significance=5;

    int MMissions=3;
    int PMissions=2;
    int EMissions=1;



    Mission  MTest;

    ReadFile(); // Give the file as an argument


    ////Rovers initializations
/*
    // Initialization for all Rovers.
    // It's better to do these initialization in the rover class itself.
    Rover* ERoverList;
    Rover* PRoverList;
    Rover* MRoverList;
    ERoverList=new Rover[NoofE];
    MRoverList=new Rover[NoofM];
    PRoverList=new Rover[NoofP];

    // I need to add all rovers to the availability Queues
    // Then dequeue the ones who got missions.
    // The one who finishes the mission will be added again to the queue, BUT CHECK the number of missions in order to make it CHECKUP or not. THIS IS a member function.

    //// initialize 3 queues for each available type rovers

    LinkedQueue<Rover> AvailableEQueue;
    LinkedQueue<Rover> AvailableMQueue;
    LinkedQueue<Rover> AvailablePQueue;

    //// These initializations will be conducted in RoverList class.
    // Then there will queue and dequeue functions there.
    for (int i = 0; i < NoofE ; ++i)
    {
        AvailableEQueue.enqueue(ERoverList[i]);
    }
     for (int i = 0; i < NoofM ; ++i)
    {
        AvailableMQueue.enqueue(MRoverList[i]);
    }
     for (int i = 0; i < NoofP ; ++i)
    {
        AvailablePQueue.enqueue(PRoverList[i]);
    }



*/
//// This becomes
RoverList RL(NoofM,NoofP,NoofE,SpeedM,SpeedP,SpeedE, CheckupDurationM,CheckupDurationP, CheckupDurationE);

//// Missions initializations

MissionList ML();





    while(true)
    {



        cout<<"Choose the Mode, 1 for interactive, 2 for step-by-step, 3 for silent mode\n";
        int mode;
        cin>>mode;
        int CompletedMission=MTest.getCompletedMission();
        Mission* executionList; //
        cout<<"";



    }



    return 0;
}
