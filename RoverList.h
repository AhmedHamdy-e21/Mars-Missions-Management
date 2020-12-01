//
// Created by raspberry on 2020-11-30.
//

#ifndef MARS_MISSIONS_MANAGEMENT_ROVERLIST_H
#define MARS_MISSIONS_MANAGEMENT_ROVERLIST_H
#include "Rover related/Rover.h"
#include "Queue/LinkedQueue.h"
#include "Rover related/Emergency_rovers.h"
#include "Rover related/Polar_rovers.h"
#include "Rover related/Mountainous_rovers.h"

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
    RoverList()
    {
        setNoofE(0);
        setNoofP(0);
        setNoofM(0);
        setERoverList(0,0,0);
        setMRoverList(0,0,0);
        setPRoverList(0,0,0);


    }
    RoverList(  int NoofM,int NoofP, int NoofE,int SpeedM,int SpeedP,int SpeedE,int CheckupDurationM,int CheckupDurationP,int CheckupDurationE)
    {
        setERoverList(NoofE,SpeedE,CheckupDurationE);
        cout<<"SM"<<SpeedM<<endl;
        setMRoverList(NoofM,SpeedM,CheckupDurationM);
        setPRoverList(NoofP,SpeedP,CheckupDurationP);
        cout<<"Number of polar is "<< NoofP;

        // I need to add all rovers to the availability Queues
        // Then dequeue the ones who got missions.
        // The one who finishes the mission will be added again to the queue, BUT CHECK the number of missions in order to make it CHECKUP or not. THIS IS a member function.

        //// initialize 3 queues for each available type rovers



        //// These initializations will be conducted in RoverList class.
        // Then there will queue and dequeue functions there.
        Queueit();
    }
    void Queueit()
    {
        for (int i = 0; i < NoofE ; ++i)
        {
            AvailableEQueue.enqueue(*ERoverList[i]);
            cout<<"I'm here\n";
        }
        for (int i = 0; i < NoofM ; ++i)
        {
            AvailableMQueue.enqueue(*MRoverList[i]);
        }
        for (int i = 0; i < NoofP ; ++i)
        {
            AvailablePQueue.enqueue(*PRoverList[i]);
            cout<<i<<endl;
        }
    }

    void setNoofE(int NoofE)
    {
        this->NoofE=NoofE;
    }
    void setNoofP(int NoofP)
    {
        this->NoofP=NoofP;
    }
    void setNoofM(int NoofM)
    {
        this->NoofM=NoofM;
    }

    void setERoverList(int NoofE,int SpeedE,int CheckupDurationE)
    {
        setNoofE( NoofE);
        ERoverList=new Emergency_rovers*[NoofE];
        for (int i=0; i<NoofE; i++)
        {
            ERoverList[i]= new Emergency_rovers(SpeedE,CheckupDurationE);
        }
        cout<<"initialized successfulle";


    }

    void setPRoverList(int NoofP,int SpeedP,int CheckupDurationP)
    {
        setNoofP(NoofP);
        PRoverList=new Polar_rovers*[NoofP];
        for (int i=0; i<NoofP; i++)
        {
            PRoverList[i]= new Polar_rovers(SpeedP,CheckupDurationP);
        }
    }

    void setMRoverList(int NoofM,int SpeedM,int CheckupDurationM)
    {
        setNoofM(NoofM);
        MRoverList=new Mountainous_rovers*[NoofM];
        for (int i=0; i<NoofM; i++)
        {
            MRoverList[i]= new Mountainous_rovers(SpeedM,CheckupDurationM);
        }
    }

    void PrintRovers()
    {
        for (int i = 0; i < NoofE; ++i)
        {
            ERoverList[i]->PrintEmergency();
        }

        for (int i = 0; i < NoofM; ++i)
        {
          MRoverList[i]->PrintMountanious();
        }

        for (int i = 0; i <NoofP; ++i)
        {
            cout<<"NO of  p"<<NoofP;
           PRoverList[i]->PrintPolar();
            cout<<endl<<i<<endl;
        }
        cout<<"Done with printingggg";
    }

    LinkedQueue<Rover> getAvailableEQueue()
    {
        return this->AvailableEQueue;
    }

    LinkedQueue<Rover> getAvailablePQueue()
    {
        return this->AvailablePQueue;
    }

    LinkedQueue<Rover> getAvailableMQueue()
    {
        return this->AvailableMQueue;
    }
};


#endif //MARS_MISSIONS_MANAGEMENT_ROVERLIST_H
