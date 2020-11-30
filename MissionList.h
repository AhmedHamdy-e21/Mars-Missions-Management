//
// Created by raspberry on 2020-11-30.
//
#pragma once
#include "Mission.h"
#include "EmergencyMissions.h"
#include "PolarMission.h"
#include "MountainousMissions.h"

class MissionList
{
private:
    Mission** ML;
    int NumberOfMissions;


public:
    MissionList();


    void AddMission(int TargetLocation,int MissionDuration,int Significance, char TYP)
    {
        if (TYP == 'E')
        {
            ML[NumberOfMissions]=new EmergencyMissions(TargetLocation,MissionDuration,Significance);
          IncrementNoOfMissions();
        }
        else if(TYP == 'M')
        {

        }
        else if(TYP == 'P')
        {

        }
    }

    void CancelMission(int ED,int ID)
    {

    }

    void PromoteMission(int ED,int ID)
    {

    }

    void PrintAllMissions()
    {

    }
    void IncrementNoOfMissions()
    {
        this->NumberOfMissions++;
    }
};


