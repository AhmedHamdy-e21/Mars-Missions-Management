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
    PolarMission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance);
    void PrintMission() override;
    virtual void setED(int ED);
    virtual int getED();
};


#endif //MARS_MISSIONS_MANAGEMENT_POLARMISSION_H
