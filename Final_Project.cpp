#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"
#include "Final_Project.h"


#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <limits>
#include <cstring>


using namespace std;

char* trimwhitespace(char* str)
{
	char* end;

	while (isspace((unsigned char)*str)) str++;

	if (*str == 0)  
		return str;


	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;

	end[1] = '\0';

	return str;
}

void pressEnter()
{
	cout << "\n<<< Press Return to Continue>>>>\n";
	cin.get();
}

void cleanStandardInputStream(void)
{
	int leftover;
	do {
	leftover = cin.get();
	} while(leftover != '\n' && leftover != EOF);
}

void display_header(){
	cout << "Version: 1.0" << endl;
	cout << "Term Project- Flight Managment Program in C++" << endl;
	cout << "Produced by: Ahmed Abbas" <<endl;
	
}



int main(){

	Flight f;
	string file = "flight_info.txt";
	int choice, wrongInput;
	f.populate_flight_from_file(file);
	display_header();
	pressEnter();


	while(choice!=6){

		cout<<"\n\n Please select one of the following options:";
		cout<<"\n 1. Display Flight Seat Map.";
		cout<<"\n 2. Display Passengers Information.";
		cout<<"\n 3. Add a New Passenger.";
		cout<<"\n 4. Remove an Existing Passenger";
		cout<<"\n 5. Save data";
		cout<<"\n 6. Quit.";

		cout<<"\n\n\n Enter your choice: (1, 2, 3, 4, 5, or 6): ";
		cin>>choice;


while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6){
	
	wrongInput++;

	if(wrongInput>5)
	{
		cout << "Program Terminatig! too many incorrect inputs entered" << endl;;
		exit(1);
	}
	else {
		cerr << "Error! Please enter a number between 1-6\n";
		cleanStandardInputStream();
		cout << "\n\nEnter your choice: (1, 2, 3, 4, 5, or 6): ";
		cin >> choice;
	}
	
	if (choice < 7 && choice > 0 && wrongInput < 5) {
		break;
	}	
}


	switch(choice){
		case 1:
			f.display_flight_map();
			cleanStandardInputStream();
			pressEnter();
			break;
		case 2:
			f.display_passengers();
			cleanStandardInputStream();
			pressEnter();
			break;
		case 3:
			f.add_passenger();
			break;
		case 4:
			f.remove_passenger();
			break;
		case 5:
			f.save_info(file);
			break;
		case 6:
			exit(1);
			break;
		}
	}
return 0;
}