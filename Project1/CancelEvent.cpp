#include "CancelEvent.h"

CancelEvent::CancelEvent(int ED, int ID, MissionList ML, RoverList RL)
{
	this->Event_Day = ED;
	this->Mission_ID = ID;
	this->ML = ML;
	this->RL = RL;
	this->eventType = Cancelation;
}

void CancelEvent::Execute()
{
	ML.CancelMission(Mission_ID);
}
