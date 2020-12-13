#include"Rover.h"

class Polar_rovers: public Rover
{
public:
    Polar_rovers(int speed, int check_up_duration) : Rover(speed, check_up_duration) {};

    void Print() override
    {
        cout<<"\n I'm Polar "<< this->getSpeed()<< this->getCheckupDuration(); //Make sure in gitkraken
    }

};