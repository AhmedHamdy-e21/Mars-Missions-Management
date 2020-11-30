#include"Rover.h"

class Mountainous_rovers : public Rover
{
	
	private:
		int check_up_duration;
		int speed;
	public:
    Mountainous_rovers(int Speed,int check_up_duration);
    void setSpeed(int speed);
    void setCheckupDuration(int  check_up_duration);
	void PrintMountanious();


};