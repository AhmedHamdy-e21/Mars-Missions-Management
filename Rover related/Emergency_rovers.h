#include"Rover.h"

class Emergency_rovers : public Rover
{
private:
	int check_up_duration;
	int speed;
public:
    Emergency_rovers(int speed,int check_up_duration) : Rover(speed, check_up_duration) {};

    void setSpeed(int speed)
    {
        this->speed=speed;
    }
    void setCheckupDuration(int  check_up_duration)
    {
        this-> check_up_duration= check_up_duration;
    }
    void Print() override
    {
        cout<<"\n I'm Emergency "<< this->speed<< this->check_up_duration;
    }


};