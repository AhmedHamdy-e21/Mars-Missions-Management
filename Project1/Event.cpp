#include "Event.h"

Event::Event()
{
}

Event::Event(int Event_Day, int Mission_ID, MissionList *ML, RoverList *RL, event eventType)
{
	this->Event_Day = Event_Day;
	this->Mission_ID = Mission_ID;
	this->ML = ML;
	this->RL = RL;
	this->eventType = eventType;
}














int Event::get_event_day()
{
	return Event_Day;
}

int Event::get_Mission_ID()
{
	return Mission_ID;
}
event Event::get_event_type()
{
	return eventType;
}
