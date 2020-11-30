//
// Created by raspberry on 2020-11-24.
//

#include "Mission.h"

Mission::Mission(int TargetLocation, int MissionDuration, int Significance)
{
    

        setCompletedMission(true);
        setMisisonDuration(MissionDuration);
        setSignificance(Significance);
        setTargetLocation(TargetLocation);
    
}

void Mission::setTargetLocation(int TargetLocation)
{
         this->TargetLocation = TargetLocation;
    
}

void Mission::setMisisonDuration(int MissionDuration)
{
    this->MissionDuration = MissionDuration;
}

void Mission::setSignificance(int Significance)
{
    this->Significance = Significance;
}

void Mission::setCompletedMission(bool BOOL)
{
    CompletedMission = BOOL;
}

bool Mission::getCompletedMission()
{

    return CompletedMission;
}
