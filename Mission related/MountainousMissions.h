//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSIONS_H
#define MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSIONS_H
#include "Mission.h"

class MountainousMissions : public Mission
        {
public:
            MountainousMissions(int TargetLocation,int MissionDuration,int Significance):Mission( TargetLocation, MissionDuration,Significance){};
    void PrintMission() override
    {
        cout<<"It's Mountainous mission right here with Target location "<< this->getTargetLocation();
    }

};


#endif //MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSIONS_H
