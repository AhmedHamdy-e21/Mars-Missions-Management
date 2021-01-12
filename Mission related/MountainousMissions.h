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
    MountainousMissions(int ED, int ID, int TargetLocation, int MissionDuration, int Significance);
    void PrintMission() override;
    virtual void setED(int ED);
    virtual int getED();
};


#endif //MARS_MISSIONS_MANAGEMENT_MOUNTAINOUSMISSIONS_H
