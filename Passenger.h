#include <iostream>
#include <string>
#include "Seat.h"
using namespace std;

#ifndef Passenger_Included
#define Passenger_Included

class Passenger{

		public:
		
		void setFirstName(const string firstN);	
		void setLastName(const string lastN);
		void setPhoneNumber(const string phoneN);
		void setSeatDetails(const int setN, const char seatL);
		void setIdNumber(const int idN);

		Passenger(); 
		Passenger(const string firstN, const string lastN, const string phoneN, const int seatN, const char seatL, const int id); 
		string getFirstName() const;
		string getLastName() const;
		string getPhoneNumber() const; 
		Seat getSeatDetails() const;
		int getIdNumber() const; 

		
		private:

		string first_name;
		string last_name;
		string phone_number;
		Seat seat_details;
		int id_number;
	};
#endif