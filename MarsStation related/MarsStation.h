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
    void loadFile();
    LinkedQueue<Event> Events;
    MarsStation();
    bool Must_Stop();
    void Simulate(int Day); // Implementation should be done by YASSER
    template<typename T>
    void AvaliableRovers(LinkedQueue<Rover> rovers, LinkedQueue<Mission> missions);

};

#endif //MARS_MISSIONS_MANAGEMENT_MARSSTATION_H

        