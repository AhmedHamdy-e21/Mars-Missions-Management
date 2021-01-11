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

    int AutoP;

public:
    void loadFile();
    LinkedQueue<Event> Events;
    LinkedQueue<FormulationEvent> Formaulation_Event;
    MarsStation();
    bool Must_Stop();
    void Simulate(int Day); // Implementation should be done by YASSER
    int AvaliableRovers(LinkedQueue<Rover> rovers, LinkedQueue<Mission> missions);
    void CancelMission(int id);
    void PromoteMission(int id);

	void AssignMissions(int Day);
   
   

};

#endif //MARS_MISSIONS_MANAGEMENT_MARSSTATION_H

