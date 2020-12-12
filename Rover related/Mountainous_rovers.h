#include"Rover.h"

class Mountainous_rovers : public Rover
{
	
	private:
		int check_up_duration;
		int speed;
	public:
    Mountainous_rovers(int Speed,int check_up_duration) : Rover(speed, check_up_duration) {};
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
        cout<<"\n I'm Mountanous "<< this->speed<< this->check_up_duration;
    }


};