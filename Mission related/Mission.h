//
// Created by raspberry on 2020-11-24.
//

#ifndef MARS_MISSIONS_MANAGEMENT_MISSION_H
#define MARS_MISSIONS_MANAGEMENT_MISSION_H
#include <iostream>
using namespace std;


enum status { Waiting, Executing, Completed };
enum type {Mountainous, Emergency, polar};
class Mission
{
    
private:
    int TargetLocation;
    int MissionDuration;
    int Significance;
    int completionDay = INT_MAX;
    int ID;
    int ED;
    int WaitingDays;
    int ExecutionDays;
 

protected:
    type Type;
    status state;
public:
    virtual int getID();
    virtual void setID(int ID);
    Mission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance);
    Mission();
    virtual void setED(int ED);
    virtual int getED();



    void setTargetLocation(int TargetLocation);
    int getTargetLocation() const;
    int getMissionDuration() const;
    void setMisisonDuration(int MissionDuration);
    void setSignificance(int Significance);
    int getSignificance();

    
    void setCompletionDay(int today, int ExecutionDays);
    int getCompletionDay();

    bool getCompletedMission(int today);

    virtual void PrintMission();

    void change_state(int state);

    status get_status();

    type get_type();

    void change_type(int typ);


    int get_WaitingDays();
    

    int  get_ExecutionDays();
};


#endif //MARS_MISSIONS_MANAGEMENT_MISSION_H
