#pragma once
#include "Event.h"
class CancelEvent :public Event
{
public:
	CancelEvent(int ED, int ID, MissionList ML, RoverList RL);
	void Execute();
};

