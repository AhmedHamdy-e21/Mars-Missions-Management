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
	int integar[12];
	int integarF[6];
	string TYP;
	
		for (int i = 0; i < 12;i++) {
			inputFile >> integar[i];

		}
		for (int j = 0; j < integar[11]; j++) {
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
		}

		cout << "The number of the mountain rover is  " << integar[0] << endl;
		cout << "The number of the polar rover is  " << integar[1] << endl;
		cout << "The number of the emergecy rover is  " << integar[2] << endl;
		cout << "The speed of all mountainous rovers is  " << integar[3] << endl;
		cout << "The speed of all polar rovers is   " << integar[4] << endl;
		cout << "The speed of all emergency rovers is " << integar[5] << endl;
		cout << "The number of missions the rover completes before performing a checkup is  " << integar[6] << endl;
		cout << "The checkup duration in days for mountainous rovers is  " << integar[7] << endl;
		cout << "The checkup duration in days for polar rovers is  " << integar[8] << endl;
		cout << "The checkup duration in days for emergency rovers is  " << integar[9] << endl;
		cout << "The number of days after which a mountainous mission is automatically promoted to an emergency mission. is  " << integar[10] << endl;
		cout << "The number of the events is  " << integar[11] << endl;
		cout << "The number of the events is  " <<TYP<<"  " << integarF[0] << endl;
		

	
	
}