//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSIONS_H
#define MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSIONS_H
#include "Mission.h"

class EmergencyMissions : public Mission
{
public:
    EmergencyMissions(int TargetLocation,int MissionDuration,int Significance):Mission( TargetLocation, MissionDuration,Significance){};


};


#endif //MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSIONS_H
