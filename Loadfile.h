void loadFile(RoverList& RL,MissionList& ML,LinkedQueue<Mission>& CurrentE,LinkedQueue<Mission> & CurrentM,LinkedQueue<Mission> &CurrentP) {
    ifstream inputFile;
 
    inputFile.open("Input Sample.txt");
    // Check for Error:
    if (inputFile.fail()) {
        cerr << "Error opening the file" << endl;
        exit(1);
    }
    else
    {
        cout << "All is good" << endl;
    }
    int M,P,E,SM,SP,SE,N,CM,CP,CE,AutoP,EV,ED,ID,TLOC,MIDUR,SIG;
    char F,TYP;

    inputFile >> M;

    inputFile >> P;
    inputFile >> E;
    inputFile >> SM;
    inputFile >> SP;
    inputFile >> SE;
    inputFile >> N;
    inputFile >> CM;
    inputFile >> CP;
    inputFile >> CE;
    inputFile >> AutoP;
    RL.setERoverList(E,SE,CE);
    RL.setMRoverList(M,SM,CM);
    RL.setPRoverList(P,SP,CP);

    inputFile >> EV;
    ML.setMissionList(EV);
    for (int j = 0; j < EV; j++)
    {
        string type;
        inputFile >> type;
        if (type == "F")
        {
            inputFile >> TYP;
            inputFile>> ED;
            inputFile>> ID;
            inputFile>> TLOC;
            inputFile>> MIDUR;
            inputFile>> SIG;

            ML.AddMission(ED,ID,TLOC,MIDUR,SIG,TYP);

        }

        else if (type == "X")
        {
            inputFile>> ED;
            inputFile>> ID;
            ML.CancelMission(ED,ID,CurrentE,CurrentM,CurrentP);;

        }
        else if (type == "P")
        {
            inputFile>> ED;
            inputFile>> ID;
            ML.PromoteMission(ED,ID);
        }
    }


    inputFile.close();

}
 
