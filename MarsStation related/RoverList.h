//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_ROVERLIST_H
#define MARS_MISSIONS_MANAGEMENT_ROVERLIST_H
#include "../Rover related/Rover.h"
#include "../Queue/LinkedQueue.h"
#include "../Rover related/Emergency_rovers.h"
#include "../Rover related/Polar_rovers.h"
#include "../Rover related/Mountainous_rovers.h"

class RoverList

{
private:
    int NoofM;
    int NoofP;
    int NoofE;
    int count = NoofE + NoofP + NoofM;
    Emergency_rovers** ERoverList;
    Polar_rovers** PRoverList;
    Mountainous_rovers** MRoverList;
    LinkedQueue<Rover> AvailableEQueue;
    LinkedQueue<Rover> AvailableMQueue;
    LinkedQueue<Rover> AvailablePQueue;
public:
    RoverList()
    {
        setNoofE(0);
        setNoofP(0);
        setNoofM(0);
        setERoverList(0, 0, 0,0);
        setMRoverList(0, 0, 0,0);
        setPRoverList(0, 0, 0,0);


    }
    RoverList(int NoofM, int NoofP, int NoofE, int SpeedM, int SpeedP, int SpeedE, int CheckupDurationM, int CheckupDurationP, int CheckupDurationE, int N)
    {
        setERoverList(NoofE, SpeedE, CheckupDurationE,N);
        setMRoverList(NoofM, SpeedM, CheckupDurationM,N);
        setPRoverList(NoofP, SpeedP, CheckupDurationP,N);
    }
   

    void setNoofE(int NoofE)
    {
        this->NoofE = NoofE;
    }
    void setNoofP(int NoofP)
    {
        this->NoofP = NoofP;
    }
    void setNoofM(int NoofM)
    {
        this->NoofM = NoofM;
    }

    void setERoverList(int NoofE, int SpeedE, int CheckupDurationE,int n)
    {
        setNoofE(NoofE);
        ERoverList = new Emergency_rovers * [NoofE];
        for (int i = 0; i < NoofE; i++)
        {
            ERoverList[i] = new Emergency_rovers(SpeedE, CheckupDurationE,n);
        }
    }

    void setPRoverList(int NoofP, int SpeedP, int CheckupDurationP,int n)
    {
        setNoofP(NoofP);
        PRoverList = new Polar_rovers * [NoofP];
        for (int i = 0; i < NoofP; i++)
        {
            PRoverList[i] = new Polar_rovers(SpeedP, CheckupDurationP,n);
        }
    }

    void setMRoverList(int NoofM, int SpeedM, int CheckupDurationM,int n)
    {
        setNoofM(NoofM);
        MRoverList = new Mountainous_rovers * [NoofM];
        for (int i = 0; i < NoofM; i++)
        {
            MRoverList[i] = new Mountainous_rovers(SpeedM, CheckupDurationM,n);
        }
    }


    LinkedQueue<Rover*> getAvailableEQueue(int day)
    {
        LinkedQueue<Rover*> availableRQueue;
        for (int i = 0; i < NoofE; i++) {
            Rover* cur = ERoverList[i];
            if (cur->getAvailiabilityDay() <= day)
                cur->setAvailablity(true);
            if (cur->checkavailability())
                availableRQueue.enqueue(cur);

        }
        return availableRQueue;
    }
    LinkedQueue<Rover*> getAvailableMQueue(int day)
    {
        LinkedQueue<Rover*> availableRQueue;
        for (int i = 0; i < NoofM; i++) {
            Rover* cur = MRoverList[i];
            if (cur->getAvailiabilityDay() <= day)
                cur->setAvailablity(true);
            if (cur->checkavailability())
                availableRQueue.enqueue(cur);

        }
        return availableRQueue;
    }

    LinkedQueue<Rover*> getAvailablePQueue(int day)
    {
        LinkedQueue<Rover*> availableRQueue;
        for (int i = 0; i < NoofP; i++) {
            Rover* cur = PRoverList[i];
            if (cur->getAvailiabilityDay() <= day)
                cur->setAvailablity(true);
            if (cur->checkavailability())
                availableRQueue.enqueue(cur);

        }
        return availableRQueue;
    }
    /* LinkedQueue<Rover> getAvailablePQueue()
     {
         return this->AvailablePQueue;
     }

     LinkedQueue<Rover> getAvailableMQueue()
     {
         return this->AvailableMQueue;
     }
 };*/

};
#endif //MARS_MISSIONS_MANAGEMENT_ROVERLIST_H
