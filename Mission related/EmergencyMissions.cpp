//
// Created by raspberry on 2020-11-30.
//

#include "EmergencyMissions.h"

EmergencyMissions::EmergencyMissions(int ED, int ID, int TargetLocation, int MissionDuration, int Significance) :Mission(ED, ID, TargetLocation, MissionDuration, Significance) {
    Type = Emergency;
}
void EmergencyMissions::PrintMission()
{
    cout << "It's emergency mission right here with Target location " << this->getTargetLocation();
}
void EmergencyMissions::setED(int ED)
{
    this->ED = ED;
}
int EmergencyMissions::getED()
{
    return this->ED;
}

