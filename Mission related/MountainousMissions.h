//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSIONS_H
#define MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSIONS_H
#include "Mission.h"

class MountainousMissions : public Mission
        {
private:
            int ED;
public:
            MountainousMissions(int ED,int ID,int TargetLocation,int MissionDuration,int Significance):Mission(ED,ID, TargetLocation, MissionDuration,Significance){};
    void PrintMission() override
    {
        cout<<"It's Mountainous mission right here with Target location "<< this->getTargetLocation();
    }
    virtual void setED(int ED)
    {
        this->ED=ED;
    }
    virtual int getED()
    {
        return this->ED;
    }

};


#endif //MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSIONS_H
