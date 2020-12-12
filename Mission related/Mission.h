//
// Created by raspberry on 2020-11-24.
//

#ifndef MARS_MISSIONS_MANAGEMENT_MISSION_H
#define MARS_MISSIONS_MANAGEMENT_MISSION_H
#include <iostream>
using namespace std;



class Mission
{
private:
    bool  FormulationDayStamp=true;
    int TargetLocation;
    int MissionDuration;
    int Significance;
    bool CompletedMission;
    int ID;
    int ED;

public:
     virtual int getID()const
    {
        return ID;
    }
    virtual void setID(int ID) 
    {
        this->ID = ID;
    }
    virtual int getDay() const
    {

         return ED;

    }
    Mission(int ED,int ID,int TargetLocation,int MissionDuration,int Significance)
    {
         setED(ED);

        setCompletedMission(false);
        setMisisonDuration(MissionDuration);
        setSignificance(Significance);
        setTargetLocation(TargetLocation);
        setID(ID);
    }
    Mission()
    {
        setCompletedMission(false);
        setMisisonDuration(0);
        setSignificance(0);
        setTargetLocation(0);

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
    void setCompletedMission(bool BOOL)
    {
        CompletedMission=BOOL;

    }
    bool getCompletedMission()
    {
        return CompletedMission;
    }

    virtual void PrintMission()
    {
     cout<<"In mission parent class \n";
    }


};


#endif //MARS_MISSIONS_MANAGEMENT_MISSION_H
