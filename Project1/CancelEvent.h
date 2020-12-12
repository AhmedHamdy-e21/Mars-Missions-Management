#pragma once
#include "Event.h"
class CancelEvent :public Event
{
public:
	CancelEvent(int ED, int ID);
	void Execute();
};

