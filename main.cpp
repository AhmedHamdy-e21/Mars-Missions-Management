
#include <iostream>
#include "Mission.h"
#include "Rover.h"
#include "Queue/LinkedQueue.h"
#include "RoverList.h"
#include "MissionList.h"

#include <fstream>
#include <string>
using namespace std;
void loadFile() {
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
    RoverList RL(M,P,E,SM,SP,SE, CM,CP, CE);

    inputFile >> EV;
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
//            cout<<TYP<<ED<<ID<<TLOC<<MIDUR<<SIG<<"\n";

        }
        else if (type == "X")
        {
            inputFile>> ED;
            inputFile>> ID;

        }
        else if (type == "P")
        {
            inputFile>> ED;
            inputFile>> ID;
        }
    }


    inputFile.close();
    cout << "The number of the mountain rover is  " << M << endl;
    cout << "The number of the polar rover is  " << P << endl;
    cout << "The number of the emergecy rover is  " << E << endl;
    cout << "The speed of all mountainous rovers is  " << SM << endl;
    cout << "The speed of all polar rovers is   " << SP << endl;
    cout << "The speed of all emergency rovers is " <<SE << endl;
    cout << "The number of missions the rover completes before performing a checkup is  " << N << endl;
    cout << "The checkup duration in days for mountainous rovers is  " << CM << endl;
    cout << "The checkup duration in days for polar rovers is  " << CP << endl;
    cout << "The checkup duration in days for emergency rovers is  " <<CE << endl;
    cout << "The number of days after which a mountainous mission is automatically promoted to an emergency mission. is  " << AutoP << endl;
    cout << "The number of the events is  " << EV << endl;
    cout << "The number of the events is  " << ID << endl;
    cout << "The number of the events is  " << ED << endl;

}


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
    loadFile();

    Mission  MTest;

//    ReadFile(); // Give the file as an argument
//// This becomes


//// Missions initializations

    MissionList ML();

//
//    while(true)
//    {
//
//
//
//        cout<<"Choose the Mode, 1 for interactive, 2 for step-by-step, 3 for silent mode\n";
//        int mode;
//        cin>>mode;
//        int CompletedMission=MTest.getCompletedMission();
//        Mission* executionList; //
//        cout<<"";
//
//
//
//    }



    return 0;
}



