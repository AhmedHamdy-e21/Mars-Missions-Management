
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
void loadFile(RoverList& RL,MissionList& ML) {
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

}

void printInteractiveMode(int Day)
{
    cout<<"Current Day:   "<<Day<<endl;
}

int main() {
    ////Initializations
    RoverList RL;

    MissionList ML;
    int Day=0;

    //// Load function:

    loadFile(RL,ML);



    while (false)
    {
        int Mode;
        cout<<"Enter The mode \n1- Interactive\n2-Silent\n3step_by-step\n";
        cin>>Mode;



        if(Mode==1)
        {
            printInteractiveMode(Day);
        }





        Day++;
    }


    return 0;
}



