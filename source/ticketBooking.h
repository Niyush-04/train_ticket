#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>
#include "Administration.h"
#include "decoration.h"
using namespace std;

class TicketBooking : public TrainManagement
{
private:
	string trainNo, nameOfPassenger, gender, seat, age, boardingStation, timing, fare, totalFare, trainInfo;
	ifstream fin;
	ofstream fout;
	int tin, numberOfPassenger, userCount;
	void storeInFile()
	{
		fout.open("Tickets.txt", ios::in | ios::app);
		fin.open("TrainFile.txt", ios::out);
		if (userCount == 1)
		{
			fout << "Train : " << trainInfo << endl;
			fout << "Ticket inquiry number: " << tin << endl << endl;
		}
		fout << "Passenger name: " << nameOfPassenger << endl;
		fout << "Gender: " << gender << "      Age: " << age << endl;
		fout << "Seat number: " << seat << endl << endl;
		if (userCount == numberOfPassenger)
		{
			fout << "_________________________" << endl;
		}
		fout.close();
		fin.close();
	}

public:
	void bookTicket()
	{
		srand(time(0));
		tin = rand() % 9000 + 1000; // train inquiry number
		trainInfo = searchTrain();
		cout << "Number of Passenger: ";
		cin >> numberOfPassenger;
		cout << "Boarding Station: ";
		cin >> boardingStation;
		for (userCount = 1; userCount <= numberOfPassenger; userCount++)
		{
			cout << "Enter name of " << userCount << "th passenger: ";
			cin.ignore();
			getline(cin, nameOfPassenger);
			cout << "Gender :";
			cin >> gender;
			cout << "Age :";
			cin >> age;
			seatNumberShow();
			cin >> seat;
			storeInFile();
		}
		system("cls");
		paymentPage(getFare(trainInfo.substr(0, 4)) * numberOfPassenger);
		cin >> fare;
		cout <<"Payment done successfully"<< endl << endl;
		seatBooked(trainInfo.substr(0, 4), numberOfPassenger);
		cout << "Please note down your TIN number for further reference: " << endl;
		cout << "\t\tTicket inquiry number: " << tin << endl << endl;
	}
	void viewBookings()
	{
		fin.open("Tickets.txt", ios::out);
		string x;
		while (getline(fin, x))
		{
			cout << x << endl;
		}
		fin.close();
	}
	void searchBooking()
	{
		fin.open("Tickets.txt", ios::out);
		string search;
		cout << "Enter train inquiry number: ";
		cin >> search;
		string y;
		while (getline(fin, y))
		{
			if (y == ("Ticket inquiry number: " + search))
			{
				while (getline(fin, y))
				{
					cout << y << endl;
					if (y == "_________________________")
					{
						break;
					}
				}
			}
		}
		fin.close();
	}
};
