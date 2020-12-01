#define MAX_size 100
template<typename T>
void Interactive(LinkedQueue <T> rovers, LinkedQueue<T> missions) {
    T Rovers, Missions;
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    bool Qbool1, Q2bool;
    int waitinglistmissions[MAX_size];
    int waitinglistrovers[MAX_size];
    int Executionlistmissions[MAX_size];
    int Executionlistrovers[MAX_size];
    Qbool1 = rovers.dequeue(Rovers);
    Q2bool = missions.dequeue(Missions);
    while (Qbool1 || Q2bool)
    {

        if (!Qbool1 && Q2bool)
        {
            waitinglistmissions[j] = Missions;
            j = j + 1;

            Q2bool = missions.dequeue(Missions);
        }
        else if (Qbool1 && !Q2bool)
        {
            waitinglistrovers[y] = Rovers;
            y = y + 1;
            Qbool1 = rovers.dequeue(Rovers);

        }
        else if (Qbool1 && Q2bool)
        {
            Executionlistmissions[i] = Missions;
            Executionlistrovers[x] = Rovers;
            i = i + 1;
            x = x + 1;
            Qbool1 = rovers.dequeue(Rovers);
            Q2bool = missions.dequeue(Missions);
        }
        else
        {
            break;
        }
    } 
