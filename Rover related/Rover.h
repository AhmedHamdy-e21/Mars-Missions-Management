//
// Created by raspberry on 2020-11-24.
//

#include<iostream>
using namespace std;
#pragma once


class Rover {
private:
	int Number_of_missions_to_checkup_after;
	int check_up_duration; // constant in subclassess,hence, no getters and setters
	float speed; // constant in subclasses,hence, no getters and setters
	int start_time_of_current_mission;
	int current_mission_duration;

public:
	//void Assign_mission(current_time)  // el mafrod akhodha men class tany
	// void checkup( number of missions ) // hatakhod 3adad el missions ely rover 3amltha
	// time WhenAvailable() //should return time that rover will be available in

	void set_Number_of_Missions_to_checkup_after(int N_missions);
	int get_Number_of_missions_to_checkup_after();
	void set_start_time_of_current_mission(int time);
	int get_start_time_of_current_mission();
	void set_current_mission_duration(int duration);
	int get_current_mission_duration();

};