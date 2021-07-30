#include "Seat.h"

Seat::Seat() {
  seatLetter = ' ';
  seatNumber = 0;
}

Seat::Seat(int seatN, char seatL) {
  seatLetter = seatL;
  seatNumber = seatN;
}

void Seat::setSeatLetter(char seatL) {
  seatLetter = seatL;
}

void Seat::setSeatNumber(int seatN) {
  seatNumber = seatN;
}

char Seat::getSeatLetter() const {
  return seatLetter;
}

int Seat::getSeatNumber() const {
  return seatNumber;
}
