#pragma once

class Event
{
protected:
	int Event_Day;
	int Mission_ID;
public:
	virtual void Execute();
};

