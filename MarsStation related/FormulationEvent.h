#pragma once
#include"Event.h"
class FormulationEvent: public Event
{
private:
	char TYP;
	int TLOC, MIDUR, SIG;

public:
	FormulationEvent(char TYP, int TLOC, int MIDUR, int SIG,int ED, int ID, MissionList ML, RoverList RL);
	void Execute();
	~FormulationEvent();
};

