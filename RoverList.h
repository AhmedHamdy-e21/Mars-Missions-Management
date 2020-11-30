//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_ROVERLIST_H
#define MARS_MISSIONS_MANAGEMENT_ROVERLIST_H
#include "Rover.h"
#include "Queue/LinkedQueue.h"
#include "Emergency_rovers.h"
#include "Polar_rovers.h"
#include "Mountainous_rovers.h"

class RoverList

{

private:
    int NoofM;
    int NoofP;
    int NoofE;
    int count=NoofE+NoofP+NoofM;
    Emergency_rovers** ERoverList;
    Polar_rovers** PRoverList;
    Mountainous_rovers** MRoverList;
    LinkedQueue<Rover> AvailableEQueue;
    LinkedQueue<Rover> AvailableMQueue;
    LinkedQueue<Rover> AvailablePQueue;




public:
    RoverList(int NoofM, int NoofP, int NoofE, int SpeedM, int SpeedP, int SpeedE, int CheckupDurationM, int CheckupDurationP, int CheckupDurationE);
    void Queueit();
    void setNoofE(int NoofE);
    void setNoofP(int NoofP);
    void setNoofM(int NoofM);
    void setERoverList(int NoofE, int SpeedE, int CheckupDurationE);
    void setPRoverList(int NoofP, int SpeedP, int CheckupDurationP);
    void setMRoverList(int NoofM, int SpeedM, int CheckupDurationM);
    void PrintRovers();




};


#endif //MARS_MISSIONS_MANAGEMENT_ROVERLIST_H
