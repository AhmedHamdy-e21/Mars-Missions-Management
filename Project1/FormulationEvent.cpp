#include "FormulationEvent.h"

FormulationEvent::FormulationEvent(char TYP, int TLOC, int MIDUR, int SIG, int ED, int ID)
{
	this->TYP = TYP;
	this->TLOC = TLOC;
	this->MIDUR = MIDUR;
	this->SIG = SIG;
	this->Event_Day = ED;
	this->Mission_ID = ID;

}

void FormulationEvent::Execute()
{
	
}
