#include "CancelEvent.h"

CancelEvent::CancelEvent()
{
}

CancelEvent::CancelEvent(int ED, int ID, MissionList * ML, RoverList *RL) : Event(ED, ID, ML, RL, Cancelation)
{

	
}

void CancelEvent::Execute()
{
	ML->CancelMission(Mission_ID);
}
