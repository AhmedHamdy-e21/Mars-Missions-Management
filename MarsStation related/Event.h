#pragma once
#include"../MarsStation related/MissionList.h"
#include"../MarsStation related/RoverList.h"
class Event
{
protected:
	int Event_Day;
	int Mission_ID;
	MissionList ML;
	RoverList RL;
	
public:
    Event();
	virtual void Execute();
	~Event();
};

