//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
#define MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
#include "Mission.h"

class PolarMission : public Mission
{
private:
    int ED;
public:
    PolarMission(int ED,int ID,int TargetLocation,int MissionDuration,int Significance):Mission(ED, ID, TargetLocation, MissionDuration,Significance){};
    void PrintMission() override
    {
        cout<<"It's Polar mission right here with Target location "<< this->getTargetLocation();
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


#endif //MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
