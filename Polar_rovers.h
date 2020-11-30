#include"Rover.h"

class Polar_rovers: public Rover
{
private:
	int check_up_duration;
	int speed;
public:
    Polar_rovers(int speed,int check_up_duration)
    {
        setSpeed(speed);
        setCheckupDuration(check_up_duration);
    }

    void setSpeed(int speed)
    {
        this->speed=speed;
    }
    void setCheckupDuration(int  check_up_duration)
    {
        this-> check_up_duration= check_up_duration;
    }
    void PrintPolar()
    {
        cout<<"\n I'm Polar "<< this->speed<< this->check_up_duration;
    }

};