#include"Mountainous_rovers.h"

Mountainous_rovers::Mountainous_rovers(int Speed, int check_up_duration)
{
    setSpeed(Speed);
    setCheckupDuration(check_up_duration);
}

void Mountainous_rovers::setSpeed(int speed)
{
    this->speed = speed;
}

void Mountainous_rovers::setCheckupDuration(int check_up_duration)
{
    this->check_up_duration = check_up_duration;
}

void Mountainous_rovers::PrintMountanious()
{
    cout << "\n I'm Mountanous " << this->speed << this->check_up_duration;
}
