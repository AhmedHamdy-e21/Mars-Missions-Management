#include"Rover.h"

class Emergency_rovers : public Rover
{
private:
	int check_up_duration; // 10 for example;
	int speed; //for example
public:
    Emergency_rovers(int speed,int check_up_duration)
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


};