//
// Created by raspberry on 2020-11-30.
//

#include "PolarMission.h"

PolarMission::PolarMission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance) :Mission(ED, ID, TargetLocation, MissionDuration, Significance) {
    Type = polar;
}
void PolarMission::PrintMission()
{
    cout << "It's Polar mission right here with Target location " << this->getTargetLocation();
}

void PolarMission::setED(int ED)
{
    this->ED = ED;
}

int PolarMission::getED()
{
    return this->ED;
}


