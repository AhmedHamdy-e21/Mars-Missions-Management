//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSIONS_H
#define MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSIONS_H
#include "Mission.h"

class EmergencyMissions : public Mission
{
private:
    int ED;
public:
    EmergencyMissions(int ED, int ID, int TargetLocation, int MissionDuration, int Significance);

    void PrintMission() override;
    virtual void setED(int ED);
    virtual int getED();

};


#endif //MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSIONS_H
