#include"Rover.h"

class Emergency_rovers : public Rover
{
private:
	int check_up_duration;
	int speed;
public:
    Emergency_rovers(int speed, int check_up_duration);
    void setSpeed(int speed);
    void setCheckupDuration(int  check_up_duration);
    void PrintEmergency();

};