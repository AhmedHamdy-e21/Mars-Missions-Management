#include "FormulationEvent.h"

FormulationEvent::FormulationEvent(char TYP, int TLOC, int MIDUR, int SIG, int ED, int ID, MissionList ML, RoverList RL)
{
	this->TYP = TYP;
	this->TLOC = TLOC;
	this->MIDUR = MIDUR;
	this->SIG = SIG;
	this->Event_Day = ED;
	this->Mission_ID = ID;
	this->ML = ML;
	this->RL = RL;
	this->eventType = Formulation;

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
