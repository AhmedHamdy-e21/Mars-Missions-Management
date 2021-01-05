#pragma once
#include"Event.h"
class FormulationEvent: public Event
{
private:
	char TYP;
	int TLOC, MIDUR, SIG;

public:
	FormulationEvent();
	FormulationEvent(char TYP, int TLOC, int MIDUR, int SIG, int ED, int ID, MissionList * ML, RoverList *RL);
	void Execute();
	char get_type();
	int get_target_location();
	int get_mission_duration();
	int get_mission_significance();
};

