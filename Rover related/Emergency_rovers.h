#include"Rover.h"

class Emergency_rovers : public Rover
{

public:
    Emergency_rovers(int Speed, int check_up_duration, int check_up_missions) : Rover(Speed, check_up_duration, check_up_missions)
    {

    }

};