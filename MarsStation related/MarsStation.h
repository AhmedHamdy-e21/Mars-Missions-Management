//
// Created by raspberry on 2020-11-24.
//

#ifndef MARS_MISSIONS_MANAGEMENT_MARSSTATION_H
#define MARS_MISSIONS_MANAGEMENT_MARSSTATION_H

#include"../Project1/CancelEvent.h"
#include"../Project1/PromoteEvent.h"
#include"../Project1/FormulationEvent.h"
#include"MissionList.h"
#include"RoverList.h"
#include "../Mission related/Mission.h"
#include "../Rover related/Rover.h"
#include "../Queue/LinkedQueue.h"
#include<iostream>
#include <fstream>
#include <string>
using namespace std;




class MarsStation {
private:
    RoverList RL;

    MissionList ML;
    LinkedQueue<Mission> CurrentE;
    LinkedQueue<Mission> CurrentM;
    LinkedQueue<Mission> CurrentP;

    LinkedQueue<Rover> AvailableEQueue;
    LinkedQueue<Rover> AvailableMQueue;
    LinkedQueue<Rover> AvailablePQueue;
public:
    template<typename T>
    void SameOrder(LinkedQueue <T> Q, LinkedQueue<T> Q1);
    void loadFile();
    LinkedQueue<Event> Events;
    MarsStation();
    bool Must_Stop();
    void Simulate(int Day); // Implementation should be done by YASSER
};


#endif //MARS_MISSIONS_MANAGEMENT_MARSSTATION_H

template<typename T>
inline void MarsStation::SameOrder(LinkedQueue<T> Q, LinkedQueue<T> Q1)
{
    T x, y;
    while (!Q.isEmpty() && !Q1.isEmpty())
    {
        Q1.dequeue(x);
        Q.dequeue(y);
        if ((Q.isEmpty() && !Q1.isEmpty()) || (!Q.isEmpty() && Q1.isEmpty()))
        {
            cout << "\n\nThis Stack and this Queue are not of the Same Order\n";
            return;
        }
        if (x == y) {

        }
        else
        {
            cout << "\n\n This Stack and this Queue are not of the Same Order\n";
            return;
        }
    }
    cout << "\n\nThis Stack and this Queue are of the Same Order\n";
}
