#include"Rover.h"

class Mountainous_rovers : public Rover
{

	public:
    Mountainous_rovers(int Speed,int check_up_duration) : Rover(Speed, check_up_duration) {};
    void Print() override
    {
        cout<<"\n I'm Mountanous "<< this->getSpeed()<< this->getCheckupDuration();
    }


};