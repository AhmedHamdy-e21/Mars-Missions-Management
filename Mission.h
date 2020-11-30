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
    Mission(int TargetLocation, int MissionDuration, int Significance);
    void setTargetLocation(int TargetLocation);
    void setMisisonDuration(int MissionDuration);
    void setSignificance(int Significance);

    // Calculate completed missions according to ..
    void setCompletedMission(bool BOOL);
    bool getCompletedMission();

};


#endif //MARS_MISSIONS_MANAGEMENT_MISSION_H
