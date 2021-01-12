//
// Created by raspberry on 2020-11-30.
//

#include "MissionList.h"

MissionList::MissionList()
{
}

bool MissionList::isEmpty()
{
	return NumberOfMissions > 0;
}

MissionList::MissionList(int EV)
{
	setMissionList(EV);
}

void MissionList::IncrementEcount()
{
	this->countEmergency++;
}

void MissionList::IncrementPcount()
{
	this->countPolar++;
}

void MissionList::IncrementMcount()
{
	this->countMountanous++;
}

void MissionList::setMissionList(int EV)
{
	ML = new Mission * [EV];
}

void MissionList::AddMission(int ED, int ID, int TargetLocation, int MissionDuration, int Significance, char TYP)
{
    //        LinkedQueue<Mission> AvailableEQueue;
    if (TYP == 'E')
    {
        ML[NumberOfMissions] = new EmergencyMissions(ED, ID, TargetLocation, MissionDuration, Significance);
        AvailableEQueue.enqueue(*ML[NumberOfMissions]);
        this->IncrementEcount();
        IncrementNoOfMissions();
    }
    else if (TYP == 'M')
    {
        ML[NumberOfMissions] = new MountainousMissions(ED, ID, TargetLocation, MissionDuration, Significance);
        //            MLM[NumberOfMissions]=new MountainousMissions(ID, TargetLocation,MissionDuration,Significance);
        AvailableMQueue.enqueue(*ML[NumberOfMissions]);
        this->IncrementMcount();

        IncrementNoOfMissions();
    }

    else if (TYP == 'P')
    {
        ML[NumberOfMissions] = new PolarMission(ED, ID, TargetLocation, MissionDuration, Significance);
        //            MLP[NumberOfMissions]=new PolarMission(ID,TargetLocation,MissionDuration,Significance);
        AvailablePQueue.enqueue(*ML[NumberOfMissions]);
        this->IncrementPcount();
        IncrementNoOfMissions();
    }

}

void MissionList::Print_Waiting_Missions()
{
    cout << "Waiting Missions: " ;
}

void MissionList::Print_Inexecution_Missions()
{
    cout << "In-Execution Missions: ";

}

void MissionList::Print_Completed_missions()
{
    cout << "Completed_missions: ";
}

void MissionList::RemoveMission(int index)
{
    int id = ML[index]->getID();
    if (ML[index]->get_status() == Waiting && ML[index]->get_type() == Mountainous) {
        delete ML[index];
        removeFromMQueueWithID(id);
        NumberOfMissions--, WatingMissions--, countMountanous--;
    }
    else cout << "Mission with ID: " << id << " can't be cancelled!!!\n";
}

void MissionList::removeFromMQueueWithID(int id)
{
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

void MissionList::CancelMission(int ID)
{
    for (int i = 0; i < NumberOfMissions; ++i) {
        if (ML[i]->getID() == ID) {

            RemoveMission(i);
            return;

        }

    }
}

void MissionList::PromoteMission(int ID)
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

void MissionList::PrintAllMissions()
{
    for (int i = 0; i < NumberOfMissions; ++i) {
        cout << endl;
        ML[i]->PrintMission();
        cout << endl;

    }
}

LinkedQueue<Mission> MissionList::getEQueue()
{
    return this->AvailableEQueue;
}

LinkedQueue<Mission> MissionList::getMQueue()
{
    return this->AvailableMQueue;
}

LinkedQueue<Mission> MissionList::getPQueue()
{
    return this->AvailablePQueue;
}

void MissionList::IncrementNoOfMissions()
{
    this->NumberOfMissions++;
}

int MissionList::getWaitingMissions()
{
    return WatingMissions;
}

int MissionList::getIn_executionMissions()
{
    return in_executionMissions;
}

void MissionList::GenerateCurrentQueue(int Day, int count, LinkedQueue<Mission>& CurrentEMission, LinkedQueue<Mission> AllMissionsQueue, int AutoP)
{
    bool DequeueCheck;
    Mission QueuedElement;
    for (int i = 0; i < count; ++i)
    {
        DequeueCheck = AllMissionsQueue.dequeue(QueuedElement);
        if (DequeueCheck) {
            if (!checkID(AllMissionsQueue, QueuedElement.getID()))
                AllMissionsQueue.enqueue(QueuedElement);
        }
        if (DequeueCheck && QueuedElement.get_type() == Mountainous && QueuedElement.get_status() == Waiting && Day - QueuedElement.getED() >= AutoP) {
            PromoteMission(QueuedElement.getID());
            CountMissionAuto_P++;
            continue;
        }
        //// This is to check for every day and get the missions from the queues that have all missions
        if (DequeueCheck && QueuedElement.getED() <= Day && QueuedElement.get_status() == Waiting)
        {
            if (!checkID(CurrentEMission, QueuedElement.getID()))
                CurrentEMission.enqueue(QueuedElement);
        }

    }
}

LinkedQueue<Mission> MissionList::getMMissions()
{
    return AvailableMQueue;
}

void MissionList::getCurrentDayMissions(int Day, LinkedQueue<Mission>& CurrentEMission, LinkedQueue<Mission>& CurrentPMission, LinkedQueue<Mission>& CurrentMMission, int AutoP)
{        //// This is more compact
    this->GenerateCurrentQueue(Day, countMountanous, CurrentMMission, AvailableMQueue, AutoP);

    this->GenerateCurrentQueue(Day, countEmergency, CurrentEMission, AvailableEQueue, AutoP);
    this->GenerateCurrentQueue(Day, countPolar, CurrentPMission, AvailablePQueue, AutoP);
}

void MissionList::getAllMissions(LinkedQueue<Mission>& CurrentEMission, LinkedQueue<Mission>& CurrentPMission, LinkedQueue<Mission>& CurrentMMission, int day)
{
    //// This is more compact
    this->GenerateAllQueue(day, countMountanous, CurrentMMission, AvailableMQueue);
    this->GenerateAllQueue(day, countEmergency, CurrentEMission, AvailableEQueue);
    this->GenerateAllQueue(day, countPolar, CurrentPMission, AvailablePQueue);
}

void MissionList::GenerateAllQueue(int day, int count, LinkedQueue<Mission>& CurrentEMission, LinkedQueue<Mission> AllMissionsQueue)
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

void MissionList::changeStateByID(int ID, status new_state)
{
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

void MissionList::changeCDByID(int ID, int today, int realduration)
{
    for (int i = 0;i < NumberOfMissions;i++) {
        if (ML[i]->getID() == ID) ML[i]->setCompletionDay(today, realduration);
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

bool MissionList::checkID(LinkedQueue<Mission>& queue, int id)
{
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

int MissionList::getcountEmergency()
{
    return countEmergency;
}

int MissionList::getcountPolar()
{
    return countPolar;
}

int MissionList::getcountMountanous()
{
    return countMountanous;
}

int MissionList::getNumberOfMissions()
{
    return NumberOfMissions;
}

int MissionList::getCountMissionAuto_P()
{
    return CountMissionAuto_P;
}
