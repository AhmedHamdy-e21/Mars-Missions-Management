#include "PromoteEvent.h"

PromoteEvent::PromoteEvent(int ED, int ID, MissionList *ML, RoverList *RL) : Event(ED, ID, ML, RL, Promotion)
{

}

void PromoteEvent::Execute()
{
	ML->PromoteMission(Mission_ID);
	
}
