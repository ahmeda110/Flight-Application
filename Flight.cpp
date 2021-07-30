#include "Seat.h"
#include "Passenger.h"
#include "Flight.h"
#include "Final_Project.h"

#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;

Flight::Flight() {
  flight_number = " ";
  flight_rows = 0;
  flight_seat_per_row = 0;
  passenger_list.resize(0);
}

Flight::Flight(string flightN, int flightR, int seatsPR, vector < Passenger > & customerL) {
  flight_number = flightN;
  flight_rows = flightR;
  flight_seat_per_row = seatsPR;
  passenger_list = customerL;
}

string Flight::getFlightNumber() {
  return flight_number;
}

int Flight::getPlaneRows() {
  return flight_rows;
}

int Flight::getSeatsPerRow() {
  return flight_seat_per_row;
}

void Flight::setFlightNumber(string flightN) {
  flight_number = flightN;
}

void Flight::setPlaneRows(int flightR) {
  flight_rows = flightR;
}

void Flight::setSeatsPerRow(int seatsPR) {
  flight_seat_per_row = seatsPR;
}

void Flight::populate_flight_from_file(string fileN) {
  string phoneNumberFile, seatDetailsFile;
  int seatNumberFile, idNumber = 0, counter = 0;
  char seatLetterFile, firstNameFile[20], lastNameFile[20];

  ifstream in_file(fileN);

  if (in_file.fail()) {
    cout << "Error! file not found. . ." << endl;;
    exit(1);
  }

  in_file >> flight_number >> flight_rows >> flight_seat_per_row;

  while (!in_file.eof()) {
    passenger_list.resize(counter + 1);
    in_file.get(firstNameFile, 20);
    in_file.get(lastNameFile, 20);

    for (int a = 0; seatDetailsFile[a] != '\0'; a++) {
      if (isdigit(seatDetailsFile[a])) {
        seatNumberFile = seatNumberFile * 10 + (seatDetailsFile[a] - '0');
      } else {
        seatLetterFile = seatDetailsFile[a];
      }
    }

    passenger_list[counter++].setFirstName(firstNameFile);
    passenger_list[counter++].setLastName(lastNameFile);
    passenger_list[counter++].setPhoneNumber(phoneNumberFile);
    passenger_list[counter++].setSeatDetails(seatNumberFile, seatLetterFile);
    passenger_list[counter++].setIdNumber(idNumber);
  }
  in_file.close();
}

void Flight::display_passengers() {
  cout.width(20);
  cout << left << "First Name";
  cout.width(20);
  cout << left << "Last Name";
  cout.width(20);
  cout << left << "Phone";
  cout.width(7);
  cout << left << "row";
  cout.width(7);
  cout << left << "seat";
  cout.width(2);
  cout << left << "id\n";
  cout << "--------------------------------------------------------------------------------" << endl;

  for (long unsigned int i = 0; i < passenger_list.size(); i++) {
    cout.width(20);
    cout << left << passenger_list[i].getFirstName();
    cout.width(20);
    cout << left << passenger_list[i].getLastName();
    cout.width(20);
    cout << left << passenger_list[i].getPhoneNumber();
    cout.width(7);
    cout << left << passenger_list[i].getSeatDetails().getSeatNumber();
    cout.width(7);
    cout << left << passenger_list[i].getSeatDetails().getSeatLetter();
    cout.width(2);
    cout << left << passenger_list[i].getIdNumber();
    cout << "\n--------------------------------------------------------------------------------" << endl;
  }
}

void Flight::add_passenger() {
  int iden, sn, bo, c = 0, c1 = 0, c2 = 0, c3 = 0;
  string first_name, l_name, p_num;
  char sc;
  passenger_list.push_back(Passenger());

  while (true) {
    cout << "\nPlease enter the passenger id:";
    if (cin >> iden) {
      bo = 0;
      for (long unsigned int i = 0; i < passenger_list.size(); i++) {
        if (passenger_list[i].getIdNumber() == iden)
          bo = 1;
      }

      if (!bo) {
        break;
      } else {
        cout << "A person with this id already exists. Please enter another id.\n";
      }
    } else {
      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
      cout << "ID invalid. Please enter a numeric id\n";
    }
    c++;
    if (c >= 3) {
      cout << "\nToo many wrong inputs. Passenger has not been added. Please try again later\n";
      passenger_list.pop_back();
      return;
    }
  }

  cleanStandardInputStream();
  cout << "please enter the passenger first name:";
  getline(cin, first_name);
  if (first_name.length() > 20) {
    cerr << "Last name length is greater than field. The maximum number of letters will be stored\n";
    first_name.erase(20, l_name.length() - 20);
  }
  cout << "please enter the passenger last name:";
  getline(cin, l_name);
  if (l_name.length() > 20) {
    cerr << "Last name length is greater than field. The maximum number of letters will be stored\n";
    l_name.erase(20, l_name.length() - 20);
  }

  while (true) {
    cout << "\nPlease enter the passenger phone number:";
    if (getline(cin, p_num)) {
      if (p_num.length() <= 12 && p_num[3] == '-' && p_num[7] == '-') {
        break;
      } else {
        cout << "Phone number invalid. Please enter a numer in the format XXX-XXX-XXXX\n";
      }
    } else {
      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
      cout << "Phone number invalid. Please enter a numer in the format XXX-XXX-XXXX\n";
    }

    c1++;
    if (c1 >= 3) {
      cout << "\nToo many wrong inputs. Passenger has not been added. Please try again later\n";
      passenger_list.pop_back();
      return;
    }

  }
  while (true) {
    while (true) {
      cout << "\nEnter the passenger's desired row:";
      if (cin >> sn) {
        if (sn >= 0 && sn <= flight_rows) {
          break;
        } else {
          cout << "Input incorrect please enter a number between 0 and " << flight_rows << "\n";
          cleanStandardInputStream();
        }
      } else {
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Input incorrect please enter a number between 0 and " << flight_rows << "\n";
      }

      c2++;
      if (c2 >= 3) {
        cout << "\nToo many wrong inputs. Passenger has not been added. Please try again later\n";
        passenger_list.pop_back();
        return;
      }

    }

    while (true) {
      cout << "\nEnter the passenger's desired seat:";
      if (cin >> sc) {
        if ((int) sc >= 97 && (int) sc <= 122) {
          sc = (char)(sc - 32);
        }
        if ((sc - 'A') >= 0 && (sc - 'A') < flight_seat_per_row) {

          break;
        } else {
          cout << "Input incorrect please enter a seat letter between A and " << (char)((flight_seat_per_row - 1) + 'A') << "\n";
          cleanStandardInputStream();
        }
      } else {
        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
        cout << "Input incorrect please enter a seat letter between A and " << (char)((flight_seat_per_row - 1) + 'A') << "\n";
      }

      c3++;
      if (c3 >= 3) {
        cout << "\nToo many wrong inputs. Passenger has not been added. Please try again later\n";
        passenger_list.pop_back();
        return;
      }

    }
    int a = 0, b;
    for (long unsigned int i = 0; i < passenger_list.size(); i++) {
      if (passenger_list[i].getSeatDetails().getSeatLetter() == sc && passenger_list[i].getSeatDetails().getSeatNumber())
        a = 1;
    }
    if (!a) {
      break;
    }

    cout << "\nSeat " << sn << sc << " is already reserved please press 1 to choose another seat\nor press 2 to return to main menu\n";

    cin >> b;
    if (b == 2)
      return;

    cin.clear();
    cin.ignore(numeric_limits < streamsize > ::max(), '\n');

  }
  passenger_list[passenger_list.size() - 1].setIdNumber(iden);
  passenger_list[passenger_list.size() - 1].setFirstName(first_name);
  passenger_list[passenger_list.size() - 1].setLastName(l_name);
  passenger_list[passenger_list.size() - 1].setPhoneNumber(p_num);
  passenger_list[passenger_list.size() - 1].setSeatDetails(sn, sc);
}

void Flight::remove_passenger() {
  int ident, a = 0, c = 0;
  while (true) {
    cout << "Please enter the id of the passenger that needs to be removed:";
    if (cin >> ident) {
      for (long unsigned int i = 0; i < passenger_list.size(); i++) {
        if (passenger_list[i].getIdNumber() == ident) {
          passenger_list.erase(passenger_list.begin() + i);
          a = 1;
        }
      }
      if (a) {
        break;
      } else {
        cout << "\nPassenger with id " << ident << " was not found in the list.\nPress 1 to enter another id or 2 to return back to main menu.";
        cin >> c;
        if (c == 2)
          return;

        cin.clear();
        cin.ignore(numeric_limits < streamsize > ::max(), '\n');
      }
    } else {
      cout << "\nID entered invalid. Please enter a numerical id.\nPress 1 to enter another id or 2 to return back to main menu.";
      cin >> c;
      if (c == 2)
        return;

      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
      cin >> c;

    }
  }
}

void Flight::display_flight_map() {
  char c[passenger_list.size()];
  int a[passenger_list.size()];
  for (long unsigned int i = 0; i < passenger_list.size(); i++) {
    c[i] = passenger_list[i].getSeatDetails().getSeatLetter();
    a[i] = passenger_list[i].getSeatDetails().getSeatNumber();

  }
  int x, i, counter;
  cout << "     ";
  for (int i = 0; i < flight_seat_per_row; i++) {
    cout << char('A' + i) << "   ";
  }
  cout << "\n";

  for (i = 0; i < flight_rows + 1; i++) {
    cout << "   ";
    for (int j = 0; j < flight_seat_per_row; j++) {
      cout << "+---";
    }
    cout << "+";
    cout << "\n";
    if (i < 10) {
      cout << i << "  ";
    } else if (i >= 10 && i < 100) {
      cout << i << " ";
    } else {
      cout << i;
    }

    for (int j = 0; j <= flight_seat_per_row; j++) {
      cout << "| ";
      counter = 0;
      for (int k = 0; c[k] != '\0'; k++) {
        x = 0;
        if (a[k] == i && j == c[k] - 'A') {
          x = 1;
          counter++;
        }
        if (x) {
          cout << "X";
        }
      }
      if (counter) {
        cout << " ";
      } else {
        cout << "  ";
      }
    }
    cout << "\n";
  }
  cout << "   ";
  for (int j = 0; j < flight_seat_per_row; j++)
    cout << "+---";
  cout << "+";
}

void Flight::save_info(string s_in) {
  ofstream outfile(s_in);
  if (outfile.fail()) {
    cout << "Error opening file...quitting\n";
    exit(1);
  }

  outfile << flight_number << "\t" << flight_rows << "\t" << flight_seat_per_row << "\n";
  for (long unsigned int i = 0; i < passenger_list.size(); i++) {
    outfile.width(20);
    outfile << left << passenger_list[i].getFirstName() << "\t";
    outfile.width(20);
    outfile << left << passenger_list[i].getLastName() << "\t";
    outfile.width(20);
    outfile << left << passenger_list[i].getPhoneNumber() << "\t";
    outfile << left << passenger_list[i].getSeatDetails().getSeatNumber() << left << passenger_list[i].getSeatDetails().getSeatLetter() << "\t";
    outfile.width(20);
    outfile << left << passenger_list[i].getIdNumber() << "\n";
  }
  outfile.close();
}
