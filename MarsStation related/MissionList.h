//
// Created by raspberry on 2020-11-30.
//
#pragma once
#include "../Mission related/Mission.h"
#include "../Mission related/EmergencyMissions.h"
#include "../Mission related/PolarMission.h"
#include "../Mission related/MountainousMissions.h"
#include "../Queue/LinkedQueue.h"


class MissionList
{
private:
    Mission** ML;
    Mission** inExectution;
    int NumberOfMissions = 0;
    LinkedQueue<Mission> AvailableEQueue;
    int countEmergency = 0;
    int countPolar = 0;
    int countMountanous = 0;
    LinkedQueue<Mission> AvailableMQueue;
    LinkedQueue<Mission> AvailablePQueue;
    int WatingMissions;
    int in_executionMissions;
    int CountMissionAuto_P = 0;

public:
    MissionList();
    bool isEmpty();
    MissionList(int EV);
    void IncrementEcount();
    void IncrementPcount();
    void IncrementMcount();
    void setMissionList(int EV);
    void AddMission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance, char TYP);
    void Print_Waiting_Missions();
    void Print_Inexecution_Missions();
    void Print_Completed_missions();
    void RemoveMission(int index);
    void removeFromMQueueWithID(int id);
    void CancelMission(int ID);
    void PromoteMission(int ID);
    void PrintAllMissions();
    LinkedQueue<Mission> getEQueue();
    LinkedQueue<Mission> getMQueue();
    LinkedQueue<Mission> getPQueue();
    void IncrementNoOfMissions();
    int getWaitingMissions();
    int getIn_executionMissions();
    void GenerateCurrentQueue(int Day, int count, LinkedQueue<Mission>& CurrentEMission, LinkedQueue<Mission> AllMissionsQueue, int AutoP);
    LinkedQueue<Mission> getMMissions();
    void getCurrentDayMissions(int Day, LinkedQueue<Mission>& CurrentEMission, LinkedQueue<Mission>& CurrentPMission, LinkedQueue<Mission>& CurrentMMission, int AutoP);
    void getAllMissions(LinkedQueue<Mission>& CurrentEMission, LinkedQueue<Mission>& CurrentPMission, LinkedQueue<Mission>& CurrentMMission, int day);
    void GenerateAllQueue(int day, int count, LinkedQueue<Mission>& CurrentEMission, LinkedQueue<Mission> AllMissionsQueue);
    void changeStateByID(int ID, status new_state);
    void changeCDByID(int ID, int today, int realduration);

    bool checkID(LinkedQueue<Mission>& queue, int id);
    int getcountEmergency();
    int getcountPolar();
    int getcountMountanous();
    int getNumberOfMissions();
    int getCountMissionAuto_P();

   
};



