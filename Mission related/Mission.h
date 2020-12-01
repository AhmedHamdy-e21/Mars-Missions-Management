//
// Created by raspberry on 2020-11-24.
//

#ifndef MARS_MISSIONS_MANAGEMENT_MISSION_H
#define MARS_MISSIONS_MANAGEMENT_MISSION_H
#include <iostream>
using namespace std;



class Mission
{
private:
    bool  FormulationDayStamp=true;
    int TargetLocation;
    int MissionDuration;
    int Significance;
    bool CompletedMission;

public:
    Mission(int TargetLocation,int MissionDuration,int Significance)
    {

        setCompletedMission(false);
        setMisisonDuration(MissionDuration);
        setSignificance(Significance);
        setTargetLocation(TargetLocation);
    }
    Mission()
    {
        setCompletedMission(false);
        setMisisonDuration(0);
        setSignificance(0);
        setTargetLocation(0);

    };



    void setTargetLocation(int TargetLocation)
    {
        this->TargetLocation=TargetLocation;
    }
    int getTargetLocation() const
    {
        return this->TargetLocation;
    }
    int getMissionDuration() const
    {
        return this->MissionDuration;
    }
    void setMisisonDuration(int MissionDuration)
    {
        this->MissionDuration=MissionDuration;
    }
    void setSignificance(int Significance)
    {
        this->Significance=Significance;
    }
    int getSignificance()
    {
        return this->Significance;
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

    virtual void PrintMission()
    {
     cout<<"In mission parent class \n";
    }


};


#endif //MARS_MISSIONS_MANAGEMENT_MISSION_H
