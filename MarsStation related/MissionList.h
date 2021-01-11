//
// Created by raspberry on 2020-11-30.
//
#pragma once
#include "../Mission related/Mission.h"
#include "../Mission related/EmergencyMissions.h"
#include "../Mission related/PolarMission.h"
#include "../Mission related/MountainousMissions.h"
#include "../Queue/LinkedQueue.h"


class MissionList
{
private:
    Mission** ML;   // all pointer to pointers should be implemented in the appropriate datatype This maybe be queue
//    Mission** MLE;
//    Mission** MLP;
//    Mission** MLM;
    Mission** inExectution;
    int NumberOfMissions=0;

    LinkedQueue<Mission> AvailableEQueue;
    int countEmergency=0;
    int countPolar=0;
    int countMountanous=0;
    LinkedQueue<Mission> AvailableMQueue;
    LinkedQueue<Mission> AvailablePQueue;
    int WatingMissions;
    int in_executionMissions;

public:
    MissionList()
    {
//        setMissionList(0);

    }
    bool isEmpty() {

        return NumberOfMissions > 0;
    }

    MissionList(int EV)
    {
        setMissionList(EV);
    }
    void IncrementEcount()
    {
        this->countEmergency++;

    }
    void IncrementPcount()
    {
        this->countPolar++;

    }
    void IncrementMcount()
    {
        this->countMountanous++;

    }
    void setMissionList(int EV)
    {
        ML=new Mission*[EV];
    }
    void AddMission(int ED,int ID,int TargetLocation,int MissionDuration,int Significance, char TYP)
    {
//        LinkedQueue<Mission> AvailableEQueue;
        if (TYP == 'E')
        {
            ML[NumberOfMissions]=new EmergencyMissions(ED,ID,TargetLocation,MissionDuration,Significance);
            AvailableEQueue.enqueue(*ML[NumberOfMissions]);
            this->IncrementEcount();
          IncrementNoOfMissions();
        }
        else if(TYP == 'M')
        {
            ML[NumberOfMissions]=new MountainousMissions(ED,ID, TargetLocation,MissionDuration,Significance);
//            MLM[NumberOfMissions]=new MountainousMissions(ID, TargetLocation,MissionDuration,Significance);
            AvailableMQueue.enqueue(*ML[NumberOfMissions]);
            this->IncrementMcount();

            IncrementNoOfMissions();
        }

        else if(TYP == 'P')
        {
            ML[NumberOfMissions]=new PolarMission(ED,ID,TargetLocation,MissionDuration,Significance);
//            MLP[NumberOfMissions]=new PolarMission(ID,TargetLocation,MissionDuration,Significance);
            AvailablePQueue.enqueue(*ML[NumberOfMissions]);
            this->IncrementPcount();
            IncrementNoOfMissions();
        }


    }
/*
    //// This is not correct to make a list of each mission type because it's unnecessary
//    void generateList()
//    {
//        for (int i = 0; i < countEmergency; ++i)
//        {
//            MLE[countEmergency]=new EmergencyMissions(ID,TargetLocation,MissionDuration,Significance);
//
//        }
//
//    }
*/
    void Print_Waiting_Missions()
    {
        cout<<"Waiting Missions: "<<"("<<"5"<<") "<<" "<<"6"<<" ("<<"8"<<")";
    }
    void Print_Inexecution_Missions()
    {
        cout<<"In-Execution Missions: ";
    }
    void Print_Completed_missions()
    {
        cout<<"Completed_missions: ";
    }
    void RemoveMission(int index) {
        int id = ML[index]->getID();
        if (ML[index]->get_status() == Waiting && ML[index]->get_type() == Mountainous) {
            delete ML[index];
            removeFromMQueueWithID(id);
            NumberOfMissions--, WatingMissions--, countMountanous--;
        }
        else cout << "Mission with ID: "<<id<<" can't be cancelled!!!\n";

    }

    void removeFromMQueueWithID(int id) {
        LinkedQueue<Mission> tempQ;
        Mission tmp;
        while (AvailableMQueue.peek(tmp)) {
            AvailableMQueue.dequeue(tmp);
            if (tmp.getID() == id)continue;
            tempQ.enqueue(tmp);
        }

        while (tempQ.peek(tmp)) {
            tempQ.dequeue(tmp);
            AvailableMQueue.enqueue(tmp);
        }
    }
    void CancelMission(int ID)
    {
        for (int i = 0; i < NumberOfMissions; ++i) {
            if (ML[i]->getID() == ID) {

                RemoveMission(i);
                return;
               
            }

        }
    }
    void PromoteMission(int ID)
    {
        for (int i = 0; i < NumberOfMissions; ++i) {
            if (ML[i]->getID() == ID && ML[i]->get_status() == Waiting && ML[i]->get_type() == Mountainous) {

                removeFromMQueueWithID(ID);
                ML[i]->change_type(1);
                AvailableEQueue.enqueue(*ML[i]);
                countMountanous--, countEmergency++;
                return;

            }
        }
        
    }
    void PrintAllMissions()
    {
        for (int i = 0; i < NumberOfMissions; ++i) {
            cout<<endl;
            ML[i]->PrintMission();
            cout<<endl;

        }
    }
    LinkedQueue<Mission> getEQueue()
    {
        return this->AvailableEQueue;
    }
    LinkedQueue<Mission> getMQueue()
    {
        return this->AvailableMQueue;
    }
    LinkedQueue<Mission> getPQueue()
    {
        return this->AvailablePQueue;
    }
    void IncrementNoOfMissions()
    {
        this->NumberOfMissions++;
    }
    int getWaitingMissions()
    {
        return WatingMissions;
    }
    int getIn_executionMissions()
    {
        return in_executionMissions;
    }

    //// Revise the syntax and check the correspondance of symbols E P and M.
    void GenerateCurrentQueue(int Day, int count,LinkedQueue<Mission>& CurrentEMission,LinkedQueue<Mission> AllMissionsQueue, int AutoP )
    {
        bool DequeueCheck;
        Mission QueuedElement;
        for (int i = 0; i < count; ++i)
        {
            DequeueCheck=AllMissionsQueue.dequeue(QueuedElement);
            if (DequeueCheck) {
                if (!checkID(AllMissionsQueue, QueuedElement.getID()))
                    AllMissionsQueue.enqueue(QueuedElement);
            }
            if (DequeueCheck && QueuedElement.get_type() == Mountainous && QueuedElement.get_status() == Waiting && Day - QueuedElement.getED() >= AutoP) {
                PromoteMission(QueuedElement.getID());
                continue;
            }
            //// This is to check for every day and get the missions from the queues that have all missions
            if(DequeueCheck&& QueuedElement.getED()<=Day && QueuedElement.get_status() == Waiting)
            {
                if (!checkID(CurrentEMission, QueuedElement.getID()))
                    CurrentEMission.enqueue(QueuedElement);
            }

        }
    }

    LinkedQueue<Mission> getMMissions() {
        return AvailableMQueue;
    }
    void getCurrentDayMissions(int Day,LinkedQueue<Mission>& CurrentEMission,LinkedQueue<Mission>& CurrentPMission,LinkedQueue<Mission>& CurrentMMission, int AutoP)
    {
        //// This is more compact
        this->GenerateCurrentQueue(Day, countMountanous, CurrentMMission, AvailableMQueue,AutoP);

        this->GenerateCurrentQueue(Day,countEmergency,CurrentEMission,AvailableEQueue,AutoP);
        this->GenerateCurrentQueue(Day,countPolar,CurrentPMission,AvailablePQueue,AutoP);
    }

    void getAllMissions(LinkedQueue<Mission>& CurrentEMission, LinkedQueue<Mission>& CurrentPMission, LinkedQueue<Mission>& CurrentMMission,int day)
    {
        //// This is more compact
        this->GenerateAllQueue( day,countMountanous, CurrentMMission, AvailableMQueue);
        this->GenerateAllQueue( day,countEmergency, CurrentEMission, AvailableEQueue);
        this->GenerateAllQueue( day,countPolar, CurrentPMission, AvailablePQueue);
    }

    void GenerateAllQueue(int day,int count, LinkedQueue<Mission>& CurrentEMission, LinkedQueue<Mission> AllMissionsQueue)
    {
        bool DequeueCheck;
        Mission QueuedElement;

        for (int i = 0; i < count; ++i)
        {
            DequeueCheck = AllMissionsQueue.dequeue(QueuedElement);

            if (DequeueCheck)
            {
                if (!checkID(AllMissionsQueue, QueuedElement.getID()))
                    AllMissionsQueue.enqueue(QueuedElement);
                if (QueuedElement.get_status() != Completed && QueuedElement.getCompletedMission(day)) {
                    changeStateByID(QueuedElement.getID(), Completed);
                    QueuedElement.change_state(Completed);
                }

                if (!checkID(CurrentEMission, QueuedElement.getID()))
                    CurrentEMission.enqueue(QueuedElement);
            }
        }
    }


    void changeStateByID(int ID, status new_state) {
        for (int i = 0;i < NumberOfMissions;i++) {
            if (ML[i]->getID() == ID) ML[i]->change_state(new_state);
        }
        Mission m;
        LinkedQueue<Mission> tmpQ;
        while (AvailableMQueue.dequeue(m)) {
            if (m.getID() == ID)
                m.change_state(new_state);
            tmpQ.enqueue(m);
        }
        while (tmpQ.dequeue(m)) {
            AvailableMQueue.enqueue(m);
        }
        while (AvailableEQueue.dequeue(m)) {
            if (m.getID() == ID)m.change_state(new_state);
            tmpQ.enqueue(m);

        }
        while (tmpQ.dequeue(m)) {
            AvailableEQueue.enqueue(m);
        }
        while (AvailablePQueue.dequeue(m)) {
            if (m.getID() == ID)m.change_state(new_state);
            tmpQ.enqueue(m);

        }
        while (tmpQ.dequeue(m)) {
            AvailablePQueue.enqueue(m);
        }
    }

    void changeCDByID(int ID, int today, int realduration ) {
        for (int i = 0;i < NumberOfMissions;i++) {
            if (ML[i]->getID() == ID) ML[i]->setCompletionDay(today,realduration);
        }
        Mission m;
        LinkedQueue<Mission> tmpQ;
        while (AvailableMQueue.dequeue(m)) {
            if (m.getID() == ID)
                m.setCompletionDay(today, realduration);
            tmpQ.enqueue(m);
        }
        while (tmpQ.dequeue(m)) {
            AvailableMQueue.enqueue(m);
        }
        while (AvailableEQueue.dequeue(m)) {
            if (m.getID() == ID)m.setCompletionDay(today, realduration);
            tmpQ.enqueue(m);

        }
        while (tmpQ.dequeue(m)) {
            AvailableEQueue.enqueue(m);
        }
        while (AvailablePQueue.dequeue(m)) {
            if (m.getID() == ID)m.setCompletionDay(today, realduration);
            tmpQ.enqueue(m);

        }
        while (tmpQ.dequeue(m)) {
            AvailablePQueue.enqueue(m);
        }
    }

    bool checkID(LinkedQueue<Mission>& queue, int id) {
        Mission tmp;
        bool q = 0;
        LinkedQueue<Mission> tmpQ;
        while (queue.dequeue(tmp)) {
            if (tmp.getID() == id) q = 1;
            tmpQ.enqueue(tmp);
        }
        while (tmpQ.dequeue(tmp))
            queue.enqueue(tmp);
        return q;
    }
 
    
};


