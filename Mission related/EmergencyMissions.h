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

    void PrintMission() override
    {
        cout<<"It's emergency mission right here with Target location "<< this->getTargetLocation();
    }

};


#endif //MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSIONS_H
