
#include <iostream>
#include "Mission related/Mission.h"
#include "Rover related/Rover.h"
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
    cout<<"Mountanous is M speed;"<<SM;
    inputFile >> SP;
    inputFile >> SE;
    inputFile >> N;
    inputFile >> CM;
    inputFile >> CP;
    inputFile >> CE;
    inputFile >> AutoP;
    RoverList RL(M,P,E,SM,SP,SE, CM,CP, CE);
//    RL.PrintRovers();
    cout<<"Done with print rover";


    inputFile >> EV;
    MissionList ML(EV);
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
            cout<<"I finished adding missions\n";
            ML.AddMission(TLOC,MIDUR,SIG,TYP);
            cout<<"I finished adding missions\n";
        }

        else if (type == "X")
        {
            inputFile>> ED;
            inputFile>> ID;
            ML.CancelMission(ED,ID);

        }
        else if (type == "P")
        {
            inputFile>> ED;
            inputFile>> ID;
            ML.PromoteMission(ED,ID);
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


int main() {
    loadFile();
    int Day=0;
//    Mission MS(200,3,3);
//    LinkedQueue<Rover> QM;

    while (false)
    {






        Day++;


    }


    return 0;
}



