//
// Created by raspberry on 2020-11-30.
//
#pragma once
#include "Mission.h"
#include "EmergencyMissions.h"
#include "PolarMission.h"
#include "MountainousMissions.h"
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
    MissionList(int EV);
    void IncrementEcount();
    void IncrementPcount();
    void IncrementMcount();
    void setMissionList(int EV);
    void AddMission(int TargetLocation, int MissionDuration, int Significance, char TYP);
    void Print_Waiting_Missions();
    void Print_Inexecution_Missions();
    void Print_Completed_missions();
    void CancelMission(int ED, int ID);
    void PromoteMission(int ED, int ID);
    void PrintAllMissions();
    void IncrementNoOfMissions();
};


