#include "Seat.h"
#include "Passenger.h"
#include "Final_Project.h"


#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <limits>
#include <cstring>


using namespace std;



#ifndef Flight_Included
#define Flight_Included

class Flight{

	public:

	Flight();
	
			
	Flight(string flightN, int flightR, int seatsPR, vector <Passenger>& customerL);
	
	void display_passengers();
	//PROMISES: Prints the passenger information in a table on the console
	
	void add_passenger();
	//PROMISES:asks the user to enter a passenger information to the console
	//and add a passenger with the entered infromation to the list
	
	
	void remove_passenger();
	//PROMISES: Asks the user to enter the id of a passenger to be removed 
	//from the list and if a passenger with the provided id exists in the list
	// removes it
	
	void display_flight_map();
	//PROMISES: shows the plane seat map with its number of rows and seat per row
	//and indicates reserved seats with an X
	
	void save_info(std::string s_in);
	//REQUIRMENTS: A string containing the filepath to the file to wich the infromation
	//should be saved
	//PROMISES: Saves the passenger information in a table format in the given test file
	
	
	void setFlightNumber(string flightN);
		
		
	void setPlaneRows(int flightR);

	
	void setSeatsPerRow(int seatsPR);

	
	string getFlightNumber();
	
	int getPlaneRows();

	
	int getSeatsPerRow();
	// PROMISES: returns the number of seats per row in a Flight object
	
	void populate_flight_from_file(std::string f);
	//REQUIRMENTS: A string containing the filepath to the file which contains
	//the passengers information
	//PROMISES: Fills the Flight object with the information in the text file
	
	
	
	
	
	private:
	string flight_number;
	int flight_rows;
	int flight_seat_per_row;
	std::vector <Passenger> passenger_list;
	

};


#endif