//
// Created by raspberry on 2020-11-24.
//

#ifndef MARS_MISSIONS_MANAGEMENT_MISSION_H
#define MARS_MISSIONS_MANAGEMENT_MISSION_H
#include <iostream>
using namespace std;



class Mission
{
protected:
    bool  FormulationDayStamp=true;
    string TargetLocation;
    float MissionDuration;
    float Significance;
    bool CompletedMission;

public:
    Mission()
    {
        this->CompletedMission= false;
    }



    // Calculate completed missions according to ..
    void setCompletedMission(bool BOOL)
    {
        CompletedMission=BOOL;

    }
    bool getCompletedMission()
    {
        return CompletedMission;
    }

};


#endif //MARS_MISSIONS_MANAGEMENT_MISSION_H
