#pragma once

class Event
{
private: 
	int Event_Day;
	int Mission_ID;
public:
	virtual void Execute();
};

