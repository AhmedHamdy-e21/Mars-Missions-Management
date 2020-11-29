//
// Created by raspberry on 2020-11-24.
//

#include "Rover.h"

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
