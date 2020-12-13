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

}

void FormulationEvent::Execute()
{
	ML.AddMission(Event_Day, Mission_ID, TLOC, MIDUR, SIG, TYP);
}
