//
// Created by raspberry on 2020-11-24.
//

#include "Rover.h"

Rover::Rover()
{
}

Rover::Rover(int spd, int check_up, int missions_to_check)
{
	speed = spd, check_up_duration = check_up, number_to_next_checkup = missions_to_check, Number_of_missions_to_checkup_after = missions_to_check;
}

void Rover::set_Number_of_Missions_to_checkup_after(int N_missions)
{
	 Number_of_missions_to_checkup_after= N_missions;
}

int Rover::get_Number_of_missions_to_checkup_after()
{
	return Number_of_missions_to_checkup_after;
}

void Rover::set_start_time_of_current_mission(int time)
{
	start_time_of_current_mission =time;
}

int Rover::get_start_time_of_current_mission()
{
	return start_time_of_current_mission;
}

void Rover::set_current_mission_duration(int duration)
{
	current_mission_duration = duration;
}

int Rover::get_current_mission_duration()
{
	return current_mission_duration;
}

void Rover::setAvailablity(bool available)
{
	this-> available = available;
	if (available)
		setAvailaibilityDay(-1);
}

void Rover::setAvailaibilityDay(int availableAtDay)
{
	this->availableAtDay = availableAtDay;
}

bool Rover::checkavailability()
{
	return available;
}

int Rover::getAvailiabilityDay()
{
	return availableAtDay;
}

void Rover::getAssigned(int start_day, int duration, int targetLocation)
{
	available = 0;
	availableAtDay = start_day + duration + ((targetLocation/speed)*2);
	number_to_next_checkup--;
	if (number_to_next_checkup == 0)
		availableAtDay += check_up_duration, number_to_next_checkup =  Number_of_missions_to_checkup_after;
	set_ExucutionDays(duration + ((targetLocation / speed) * 2));
}

void Rover::set_ExucutionDays(int ExecutionDays)
{
	this->ExecutionDays = ExecutionDays;
}

int Rover::get_ExecutionDays()
{
	return ExecutionDays;
}
