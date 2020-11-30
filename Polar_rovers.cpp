#include"Polar_rovers.h"

Polar_rovers::Polar_rovers(int speed, int check_up_duration)
{
	setSpeed(speed);
	setCheckupDuration(check_up_duration);
}

void Polar_rovers::setSpeed(int speed)
{
	this->speed = speed;
}

void Polar_rovers::setCheckupDuration(int check_up_duration)
{
	this->check_up_duration = check_up_duration;
}

void Polar_rovers::PrintPolar()
{
	cout << "\n I'm Polar " << this->speed << this->check_up_duration;
}
