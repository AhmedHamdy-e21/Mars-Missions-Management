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
    EmergencyMissions(int ED,int ID,int TargetLocation,int MissionDuration,int Significance):Mission(ED,ID, TargetLocation, MissionDuration,Significance){};

    void PrintMission() override
    {
        cout<<"It's emergency mission right here with Target location "<< this->getTargetLocation();
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


#endif //MARS_MISSIONS_MANAGEMENT_EMERGENCYMISSIONS_H
