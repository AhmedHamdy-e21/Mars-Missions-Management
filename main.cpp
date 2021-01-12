
#include <iostream>
#include "Mission related/Mission.h"
#include "Rover related/Rover.h"
#include "Queue/LinkedQueue.h"
#include "MarsStation related/RoverList.h"
#include "MarsStation related/MissionList.h"
#include"MarsStation related/MarsStation.h"


using namespace std;



int main() {
    
    MarsStation Station = MarsStation();
    Station.loadFile();
    int Day_Counter = 1;
  
    while (!Station.Must_Stop()) {
        Station.Simulate(Day_Counter++);
    }

}

