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
    int TargetLocation;
    int MissionDuration;
    int Significance;
    bool CompletedMission;

public:
    Mission(int TargetLocation,int MissionDuration,int Significance)
    {

        setCompletedMission(true);
        setMisisonDuration(MissionDuration);
        setSignificance(Significance);
        setTargetLocation(TargetLocation);
    }


    void setTargetLocation(int TargetLocation)
    {
        this->TargetLocation=TargetLocation;
    }
    void setMisisonDuration(int MissionDuration)
    {
        this->MissionDuration=MissionDuration;
    }
    void setSignificance(int Significance)
    {
        this->Significance=Significance;
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
