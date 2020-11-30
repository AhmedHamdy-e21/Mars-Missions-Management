#include"Rover.h"

class Mountainous_rovers : public Rover
{
	
	private:
		int check_up_duration;
		int speed;
	public:
    Mountainous_rovers(int Speed,int check_up_duration)
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