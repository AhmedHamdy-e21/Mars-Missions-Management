//
// Created by raspberry on 2020-11-24.
//

#include<iostream>
using namespace std;
#pragma once


class Rover {
private:
	int Number_of_missions_to_checkup_after;
	int number_to_next_checkup;
	int check_up_duration; 
	float speed; 
	int start_time_of_current_mission;
	int current_mission_duration;
	bool available = 1;
	int availableAtDay = -1;
	

public:
	
	Rover();
	Rover(int spd, int check_up, int missions_to_check);
	void set_Number_of_Missions_to_checkup_after(int N_missions);
	int get_Number_of_missions_to_checkup_after();
	void set_start_time_of_current_mission(int time);
	int get_start_time_of_current_mission();
	void set_current_mission_duration(int duration);
	int get_current_mission_duration();
	void setAvailablity(bool available);
	void setAvailaibilityDay(int availableAtDay);
	bool checkavailability();
	int getAvailiabilityDay();
	void getAssigned(int start_day,int duration);
	
	float getSpeed();
	
};