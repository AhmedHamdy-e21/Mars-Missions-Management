#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
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
	inputFile >> EV;
	/*for (int j = 0; j < integar[11]; j++) {
		string type;
		inputFile >> type;
		if (type == "F") {
			inputFile >> TYP;
			for (int i = 0; i < 5;i++) {
				inputFile >> integarF[i];
			}

		}
		else if (type == "X") {

		}
		else if (type == "P") {

		}
	}*/
	string type;
	string TYP;
	for (int i = 0;i < EV;i++) {
		inputFile >> type;
		if (type == "F") {
			inputFile >>TYP;
			for (int i = 0; i < 5;i++) {
				inputFile >> ED;
				inputFile >> ID;
				inputFile >> TLOC;
				inputFile >> MIDUR;
				inputFile >> SIG;
			
			}
		}
		else if (type == "X") {
			for (int i = 0; i < 2;i++) {
				inputFile >> ED;
				inputFile >> ID;

			}

		}
		else if (type == "P") {
			for (int i = 0; i < 2;i++) {
				inputFile >> ED;
				inputFile >> ID;

			}

		}


	}
	inputFile.close();
	cout << "The number of the mountain rover is  " << M << endl;
	cout << "The number of the polar rover is  " << P << endl;
	cout << "The number of the emergecy rover is  " << E << endl;
	cout << "The speed of all mountainous rovers is  " << SM << endl;
	cout << "The speed of all polar rovers is   " << SP << endl;
	cout << "The speed of all emergency rovers is " <<SE << endl;
	cout << "The number of missions the rover completes before performing a checkup is  " << N << endl;
	cout << "The checkup duration in days for mountainous rovers is  " << CM << endl;
	cout << "The checkup duration in days for polar rovers is  " << CP << endl;
	cout << "The checkup duration in days for emergency rovers is  " <<CE << endl;
	cout << "The number of days after which a mountainous mission is automatically promoted to an emergency mission. is  " << AutoP << endl;
	/*cout << "The number of the events is  " << EV << endl;
	cout << "The number of the events is  " << ID << endl;
	cout << "The number of the events is  " << ED << endl;
	*/




}