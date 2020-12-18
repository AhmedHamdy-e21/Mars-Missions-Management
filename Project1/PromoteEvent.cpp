#include "PromoteEvent.h"

PromoteEvent::PromoteEvent(int ED, int ID, MissionList ML, RoverList RL)
{
	this->Event_Day = ED;
	this->Mission_ID = ID;
	this->ML = ML;
	this->RL = RL;
	this->eventType = Promotion;
}

void PromoteEvent::Execute()
{
	ML.PromoteMission(Mission_ID);
	
}
