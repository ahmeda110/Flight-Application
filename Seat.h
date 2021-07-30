#include <iostream>

using namespace std;

#ifndef Seat_Included
#define Seat_Included

class Seat {

  public:

    Seat();
  Seat(int seatN, char seatL);

  void setSeatLetter(char seatL);
  void setSeatNumber(int seatN);
  char getSeatLetter() const;
  int getSeatNumber() const;

  private:

    int seatNumber;
  char seatLetter;
};

#endif
