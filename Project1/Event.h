#pragma once
#include"../MarsStation related/MissionList.h"
#include"../MarsStation related/RoverList.h"


enum event { Formulation, Cancelation , Promotion};
class Event
{
protected:
	int Event_Day;
	int Mission_ID;
	MissionList ML;
	RoverList RL;
	event eventType;
	
public:
	Event();
	Event(int Event_Day, int Mission_ID, MissionList ML, RoverList RL, event eventType);
	virtual void Execute() const;
	int get_event_day();
	int get_Mission_ID();
	event get_event_type();
};

