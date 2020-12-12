#pragma once
#include "Event.h"
class CancelEvent :public Event
{
public:
	void Execute();
};

