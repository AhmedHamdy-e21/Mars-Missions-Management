#pragma once
#include "Event.h"
class PromoteEvent :public Event
{
public:
	PromoteEvent(int ED, int ID, MissionList ML, RoverList RL);
	void Execute();
};

