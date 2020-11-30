#include "Emergency_rovers.h"

Emergency_rovers::Emergency_rovers(int speed, int check_up_duration)
{
	setSpeed(speed);
	setCheckupDuration(check_up_duration);
}

void Emergency_rovers::setSpeed(int speed)
{
	this->speed = speed;
}

void Emergency_rovers::setCheckupDuration(int check_up_duration)
{
	this->check_up_duration = check_up_duration;
}

void Emergency_rovers::PrintEmergency()
{
		cout << "\n I'm Emergency " << this->speed << this->check_up_duration;
	
}
