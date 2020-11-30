//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
#define MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
#include "Mission.h"

class PolarMission : public Mission
{
public:
    PolarMission(int TargetLocation,int MissionDuration,int Significance):Mission( TargetLocation, MissionDuration,Significance){};

};


#endif //MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
