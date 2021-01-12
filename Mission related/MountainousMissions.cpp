//
// Created by raspberry on 2020-11-30.
//

#include "MountainousMissions.h"

MountainousMissions::MountainousMissions(int ED, int ID, int TargetLocation, int MissionDuration, int Significance) :Mission(ED, ID, TargetLocation, MissionDuration, Significance) {
    Type = Mountainous;
}

void MountainousMissions::PrintMission()
{
    cout << "It's Mountainous mission right here with Target location " << this->getTargetLocation();
}

void MountainousMissions::setED(int ED)
{
     this->ED = ED;
    
}

int MountainousMissions::getED()
{
    return this->ED;
}
