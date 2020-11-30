//
// Created by raspberry on 2020-11-30.
//

#include "MissionList.h"

MissionList::MissionList(int EV)
{
	setMissionList(EV);
}

void MissionList::IncrementEcount()
{
        this->countEmergency++;

    
}

void MissionList::IncrementPcount()
{
    this->countPolar++;
}

void MissionList::IncrementMcount()
{

    this->countMountanous++;
}

void MissionList::setMissionList(int EV)
{
    ML = new Mission * [EV];
}

void MissionList::AddMission(int TargetLocation, int MissionDuration, int Significance, char TYP)
{
    if (TYP == 'E')
    {
        ML[NumberOfMissions] = new EmergencyMissions(TargetLocation, MissionDuration, Significance);
        AvailableEQueue.enqueue(*ML[NumberOfMissions]);
        this->IncrementEcount();
        IncrementNoOfMissions();
    }
    else if (TYP == 'M')
    {
        ML[NumberOfMissions] = new MountainousMissions(TargetLocation, MissionDuration, Significance);
        AvailableMQueue.enqueue(*ML[NumberOfMissions]);
        this->IncrementMcount();

        IncrementNoOfMissions();

    }
    else if (TYP == 'P')
    {
        ML[NumberOfMissions] = new PolarMission(TargetLocation, MissionDuration, Significance);
        AvailablePQueue.enqueue(*ML[NumberOfMissions]);
        this->IncrementPcount();
        IncrementNoOfMissions();

    }
}

void MissionList::Print_Waiting_Missions()
{
    cout << "Waiting Missions: " << "(" << "5" << ") " << " " << "6" << " (" << "8" << ")";
}

void MissionList::Print_Inexecution_Missions()
{
    cout << "In-Execution Missions: ";
}

void MissionList::Print_Completed_missions()
{
    cout << "Completed_missions: ";
}

void MissionList::CancelMission(int ED, int ID)
{
}

void MissionList::PromoteMission(int ED, int ID)
{
}

void MissionList::PrintAllMissions()
{
}

void MissionList::IncrementNoOfMissions()
{
    this->NumberOfMissions++;
}
