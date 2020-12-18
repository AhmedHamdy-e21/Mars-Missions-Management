#include "FormulationEvent.h"

FormulationEvent::FormulationEvent(char TYP, int TLOC, int MIDUR, int SIG, int ED, int ID, MissionList ML, RoverList RL): Event(ED, ID, ML, RL, Formulation)
{
	this->TYP = TYP;
	this->TLOC = TLOC;
	this->MIDUR = MIDUR;
	this->SIG = SIG;
	
	

}

void FormulationEvent::Execute()
{
	ML.AddMission(Event_Day, Mission_ID, TLOC, MIDUR, SIG, TYP);
}

char FormulationEvent::get_type()
{
	return TYP;
}

int FormulationEvent::get_target_location()
{
	return TLOC;
}

int FormulationEvent::get_mission_duration()
{
	return MIDUR;
}

int FormulationEvent::get_mission_significance()
{
	return SIG;
}
