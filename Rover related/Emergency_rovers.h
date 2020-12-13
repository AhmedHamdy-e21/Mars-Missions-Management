#include"Rover.h"

class Emergency_rovers : public Rover
{
public:
    Emergency_rovers(int speed,int check_up_duration) : Rover(speed, check_up_duration) {};

  
    void Print() override  //Make sure in gitkraken
    {
        cout<<"\n I'm Emergency "<< this->getSpeed()<< this->getCheckupDuration();
    }


};