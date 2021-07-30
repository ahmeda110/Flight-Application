#include "Passenger.h"

Passenger::Passenger() {
  first_name = (" ");
  last_name = (" ");
  phone_number = (" ");
  seat_details = Seat();
  id_number = 0;
}

Passenger::Passenger(const string firstN,
  const string lastN,
    const string phoneN,
      const int seatN,
        const char seatL,
          const int id) {
  first_name = firstN;
  last_name = lastN;
  phone_number = phoneN;
  seat_details = Seat(seatN, seatL);
  id_number = id;
}

//setters
void Passenger::setFirstName(const string firstN) {
  first_name = firstN;
}

void Passenger::setLastName(const string lastN) {
  last_name = lastN;
}

void Passenger::setPhoneNumber(const string phoneN) {
  phone_number = phoneN;
}

void Passenger::setSeatDetails(const int seatN,
  const char seatL) {
  seat_details.setSeatLetter(seatL);
  seat_details.setSeatNumber(seatN);
}

void Passenger::setIdNumber(const int idN) {
  id_number = idN;
}

//getters
string Passenger::getFirstName() const {
  return first_name;
}

string Passenger::getLastName() const {
  return last_name;
}

string Passenger::getPhoneNumber() const {
  return phone_number;
}

Seat Passenger::getSeatDetails() const {
  return seat_details;
}

int Passenger::getIdNumber() const {
  return id_number;
}
