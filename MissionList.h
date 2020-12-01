//
// Created by raspberry on 2020-11-30.
//
#pragma once
#include "Mission related/Mission.h"
#include "Mission related/EmergencyMissions.h"
#include "Mission related/PolarMission.h"
#include "Mission related/MountainousMissions.h"
#include "Queue/LinkedQueue.h"
// I was about to include sth

class MissionList
{
private:
    Mission** ML;   // all pointer to pointers should be implemented in the appropriate datatype
    Mission** inExectution;
    int NumberOfMissions=0;
    LinkedQueue<Mission> AvailableEQueue;
    int countEmergency=0;
    int countPolar=0;
    int countMountanous=0;
    LinkedQueue<Mission> AvailableMQueue;
    LinkedQueue<Mission> AvailablePQueue;


public:
    MissionList()
    {
//        setMissionList(0);

    }
    MissionList(int EV)
    {
        setMissionList(EV);
    }
    void IncrementEcount()
    {
        this->countEmergency++;

    }
    void IncrementPcount()
    {
        this->countPolar++;

    }
    void IncrementMcount()
    {
        this->countMountanous++;

    }


    void setMissionList(int EV)
    {
        ML=new Mission*[EV];
    }

    void AddMission(int TargetLocation,int MissionDuration,int Significance, char TYP)
    {
//        LinkedQueue<Mission> AvailableEQueue;
        if (TYP == 'E')
        {
            ML[NumberOfMissions]=new EmergencyMissions(TargetLocation,MissionDuration,Significance);
            AvailableEQueue.enqueue(*ML[NumberOfMissions]);
            this->IncrementEcount();
            ML[NumberOfMissions]->getTargetLocation();

          IncrementNoOfMissions();
        }
        else if(TYP == 'M')
        {
            ML[NumberOfMissions]=new MountainousMissions(TargetLocation,MissionDuration,Significance);
            AvailableMQueue.enqueue(*ML[NumberOfMissions]);
            this->IncrementMcount();

            IncrementNoOfMissions();
        }

        else if(TYP == 'P')
        {
            ML[NumberOfMissions]=new PolarMission(TargetLocation,MissionDuration,Significance);
            AvailablePQueue.enqueue(*ML[NumberOfMissions]);
            this->IncrementPcount();
            IncrementNoOfMissions();
        }


    }



    void Print_Waiting_Missions()
    {
        cout<<"Waiting Missions: "<<"("<<"5"<<") "<<" "<<"6"<<" ("<<"8"<<")";
    }

    void Print_Inexecution_Missions()
    {
        cout<<"In-Execution Missions: ";
    }
    void Print_Completed_missions()
    {
        cout<<"Completed_missions: ";
    }





    void CancelMission(int ED,int ID)
    {
    }

    void PromoteMission(int ED,int ID)
    {

    }

    void PrintAllMissions()
    {
        for (int i = 0; i < NumberOfMissions; ++i) {
            cout<<endl;
            ML[i]->PrintMission();
            cout<<endl;

        }

    }

    LinkedQueue<Mission> getEQueue()
    {
        return this->AvailableEQueue;
    }
    LinkedQueue<Mission> getMQueue()
    {
        return this->AvailableMQueue;
    }

    LinkedQueue<Mission> getPQueue()
    {
        return this->AvailablePQueue;
    }


    void IncrementNoOfMissions()
    {
        this->NumberOfMissions++;
    }
};


