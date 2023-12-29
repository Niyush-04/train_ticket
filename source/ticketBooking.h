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
			fout << "Ticket inquiry number: " << tin << endl;
			fout << "Train : " << trainInfo << endl;
			fout << "Total number of passengers: " << numberOfPassenger << endl << endl;
		}
		fout << "Passenger name: " << nameOfPassenger << endl;
		fout << "Gender: " << gender << "      Age:  " << age << endl;
		fout << "Seat number: " << seat << endl;
		if (userCount == numberOfPassenger)
		{
			fout << "_________________________" << endl;
		}
		else fout << endl;
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
		cout << "Payment done successfully" << endl
			 << endl;
		seatBooked(trainInfo.substr(0, 4), numberOfPassenger, 0);
		cout << "Please note down your TIN number for further reference: " << endl;
		cout << "\t\tTicket inquiry number: " << tin << endl
			 << endl;
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

    void cancelTicket()
    {
        ifstream readTicket("Tickets.txt");
        string search, line;
        cout << "Enter ticket inquiry number: ";
        cin >> search;
		while(getline(readTicket, line)){
			if (line == "Ticket inquiry number: " + search){
				string tn, nop, y;
				getline(readTicket,y);
				tn = y.substr(8,4); 
				getline(readTicket,y);
				nop = y.substr(28,1);
				cout<<tn<<nop<<endl;
				seatBooked(tn, 0, stoi(nop));
			}
		}
		readTicket.close();

		ifstream trainIn("Tickets.txt");
        ofstream tempFile("TempFile.txt");
        bool found = false;
        while (getline(trainIn, line))
        {
            if (line == "Ticket inquiry number: " + search)
            {
				found = true;
                while (getline(trainIn, line))
                {
                    if (line == "_________________________")
                        break;
                }
            }
            else
            {
                tempFile << line << '\n';
            }
        }
        trainIn.close();
        tempFile.close();
        if (!found)
            cout << "Ticket not found in the file." << endl;
        else
        {
            remove("Tickets.txt");
            rename("TempFile.txt", "Tickets.txt");
            cout << "Ticket cancelled successfully." << endl;
        }
    }
};
