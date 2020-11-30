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

public:
    RoverList(  int NoofM,int NoofP, int NoofE,int SpeedM,int SpeedP,int SpeedE,int CheckupDurationM,int CheckupDurationP,int CheckupDurationE)
    {

        Emergency_rovers** ERoverList=new Emergency_rovers*[NoofE];
        for (int i=0; i<NoofE; i++){
            ERoverList[i]= new Emergency_rovers(SpeedE,CheckupDurationE);
        }

        Polar_rovers** PRoverList=new Polar_rovers*[NoofP];
        for (int i=0; i<NoofP; i++){
            PRoverList[i]= new Polar_rovers(SpeedP,CheckupDurationP);
        }

        Mountainous_rovers** MRoverList=new Mountainous_rovers*[NoofM];
        for (int i=0; i<NoofM; i++){
            MRoverList[i]= new Mountainous_rovers(SpeedM,CheckupDurationM);
        }

        // I need to add all rovers to the availability Queues
        // Then dequeue the ones who got missions.
        // The one who finishes the mission will be added again to the queue, BUT CHECK the number of missions in order to make it CHECKUP or not. THIS IS a member function.

        //// initialize 3 queues for each available type rovers

        LinkedQueue<Rover> AvailableEQueue;
        LinkedQueue<Rover> AvailableMQueue;
        LinkedQueue<Rover> AvailablePQueue;

        //// These initializations will be conducted in RoverList class.
        // Then there will queue and dequeue functions there.
        for (int i = 0; i < NoofE ; ++i)
        {
            AvailableEQueue.enqueue(*ERoverList[i]);
        }
        for (int i = 0; i < NoofM ; ++i)
        {
            AvailableMQueue.enqueue(*MRoverList[i]);
        }
        for (int i = 0; i < NoofP ; ++i)
        {
            AvailablePQueue.enqueue(*PRoverList[i]);
        }


    }


};


#endif //MARS_MISSIONS_MANAGEMENT_ROVERLIST_H
