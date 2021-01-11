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
 

protected:
    type Type;
    status state;
public:
     virtual int getID()
    {
        return ID;
    }
    virtual void setID(int ID)
    {
        this->ID = ID;
    }

    Mission(int ED,int ID,int TargetLocation,int MissionDuration,int Significance)
    {
         setED(ED);

        setMisisonDuration(MissionDuration);
        setSignificance(Significance);
        setTargetLocation(TargetLocation);
        setID(ID);
        state = Waiting;
    }
    Mission()
    {
        setMisisonDuration(0);
        setSignificance(0);
        setTargetLocation(0);
        state = Waiting;
    };

    virtual void setED(int ED)
     {
         this->ED=ED;
     }
     virtual int getED()
     {
         return this->ED;
     }



    void setTargetLocation(int TargetLocation)
    {
        this->TargetLocation=TargetLocation;
    }
    int getTargetLocation() const
    {
        return this->TargetLocation;
    }
    int getMissionDuration() const
    {
        return this->MissionDuration;
    }
    void setMisisonDuration(int MissionDuration)
    {
        this->MissionDuration=MissionDuration;
    }
    void setSignificance(int Significance)
    {
        this->Significance=Significance;
    }
    int getSignificance()
    {
        return this->Significance;
    }

    // Calculate completed missions according to ..
    void setCompletionDay(int day)
    {
        completionDay=day;

    }
    bool getCompletedMission(int today)
    {
        return completionDay<=today;
    }

    virtual void PrintMission()
    {
     cout<<"In mission parent class \n";
    }

    void change_state(int state) {

        this->state = status(state);
    }

    status get_status() {
        return state;
    }

    type get_type() {
        return Type;
    }
    void change_type(int typ) {

        this-> Type = type(typ);
    }
  
};


#endif //MARS_MISSIONS_MANAGEMENT_MISSION_H
