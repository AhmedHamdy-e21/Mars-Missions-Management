//
// Created by raspberry on 2020-11-24.
//

#include "Mission.h"

int Mission::getID()
{
	return ID;
}

void Mission::setID(int ID)
{
	this->ID = ID;
}

Mission::Mission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance)
{
    setED(ED);

    setMisisonDuration(MissionDuration);
    setSignificance(Significance);
    setTargetLocation(TargetLocation);
    setID(ID);
    state = Waiting;
}

Mission::Mission()
{
    setMisisonDuration(0);
    setSignificance(0);
    setTargetLocation(0);
    state = Waiting;
}

void Mission::setED(int ED)
{
    this->ED = ED;
}

int Mission::getED()
{
    return this->ED;
}

void Mission::setTargetLocation(int TargetLocation)
{
    this->TargetLocation = TargetLocation;
}

int Mission::getTargetLocation() const
{
    return this->TargetLocation;
}

int Mission::getMissionDuration() const
{
    return this->MissionDuration;
}

void Mission::setMisisonDuration(int MissionDuration)
{
    this->MissionDuration = MissionDuration;
}

void Mission::setSignificance(int Significance)
{
    this->Significance = Significance;
}

int Mission::getSignificance()
{
    return this->Significance;
}

void Mission::setCompletionDay(int today, int ExecutionDays)
{
    completionDay = today + ExecutionDays;

    this->ExecutionDays = ExecutionDays;

    this->WaitingDays = today - ED;
}

int Mission::getCompletionDay()
{

    return completionDay;
}

bool Mission::getCompletedMission(int today)
{
    return completionDay <= today;
}

void Mission::PrintMission()
{
    cout << "In mission parent class \n";
}

void Mission::change_state(int state)
{
    this->state = status(state);
}

status Mission::get_status()
{
    return state;
}

type Mission::get_type()
{
    return Type;
}

void Mission::change_type(int typ)
{
    this->Type = type(typ);
}

int Mission::get_WaitingDays()
{
    return WaitingDays;
}

int Mission::get_ExecutionDays()
{
    return ExecutionDays;
}
