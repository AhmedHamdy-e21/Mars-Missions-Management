#include "RoverList.h"

RoverList::RoverList()
{
    setNoofE(0);
    setNoofP(0);
    setNoofM(0);
    setERoverList(0, 0, 0, 0);
    setMRoverList(0, 0, 0, 0);
    setPRoverList(0, 0, 0, 0);
}

RoverList::RoverList(int NoofM, int NoofP, int NoofE, int SpeedM, int SpeedP, int SpeedE, int CheckupDurationM, int CheckupDurationP, int CheckupDurationE, int N)
{
    setERoverList(NoofE, SpeedE, CheckupDurationE, N);
    setMRoverList(NoofM, SpeedM, CheckupDurationM, N);
    setPRoverList(NoofP, SpeedP, CheckupDurationP, N);
}

void RoverList::setNoofE(int NoofE)
{
    this->NoofE = NoofE;
}

void RoverList::setNoofP(int NoofP)
{
    this->NoofP = NoofP;
}

void RoverList::setNoofM(int NoofM)
{
    this->NoofM = NoofM;
}

void RoverList::setERoverList(int NoofE, int SpeedE, int CheckupDurationE, int n)
{
    setNoofE(NoofE);
    ERoverList = new Emergency_rovers * [NoofE];
    for (int i = 0; i < NoofE; i++)
    {
        ERoverList[i] = new Emergency_rovers(SpeedE, CheckupDurationE, n);
    }
}

void RoverList::setPRoverList(int NoofP, int SpeedP, int CheckupDurationP, int n)
{
    setNoofP(NoofP);
    PRoverList = new Polar_rovers * [NoofP];
    for (int i = 0; i < NoofP; i++)
    {
        PRoverList[i] = new Polar_rovers(SpeedP, CheckupDurationP, n);
    }
}

void RoverList::setMRoverList(int NoofM, int SpeedM, int CheckupDurationM, int n)
{
    setNoofM(NoofM);
    MRoverList = new Mountainous_rovers * [NoofM];
    for (int i = 0; i < NoofM; i++)
    {
        MRoverList[i] = new Mountainous_rovers(SpeedM, CheckupDurationM, n);
    }
}

LinkedQueue<Rover*> RoverList::getAvailableEQueue(int day)
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

LinkedQueue<Rover*> RoverList::getAvailableMQueue(int day)
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

LinkedQueue<Rover*> RoverList::getAvailablePQueue(int day)
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
