#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TrainManagement
{
private:
    string trainNumber, numberOfSeats, nameOfTrain, route, timing, fare, line, y;

    ofstream trainIn;
    ifstream trainOut;

    void trainData()
    {
        trainIn.open("TrainFile.txt", ios::in | ios::app);
        trainIn << "Train number: " << trainNumber << endl;
        trainIn << "Name of train: " << nameOfTrain << endl;
        trainIn << "Route: " << route << endl;
        trainIn << "Number of seats: " << numberOfSeats << endl;
        trainIn << "Timing: " << timing << endl;
        trainIn << "Fare: " << fare << endl;
        trainIn << "__________________________" << endl;
        trainIn.close();
    }

public:
    void addNewTrain()
    {
        cout << "Enter train number (4 digits): ";
        cin >> trainNumber;

        cin.ignore();

        cout << "Enter train name: ";
        getline(cin, nameOfTrain);

        cout << "Enter route: ";
        getline(cin, route);

        cout << "Enter timings (eg. 6:00pm-7:00am): ";
        cin >> timing;

        cout << "Enter number of seats: ";
        cin >> numberOfSeats;

        cout << "Enter fare: ";
        cin >> fare;

        trainData();
    }

    void viewTrains()
    {
        trainOut.open("TrainFile.txt", ios::out);
        string x;
        while (getline(trainOut, x))
        {
            cout << x << endl;
        }
        trainOut.close();
    }

    string searchTrain()
    {
    retry1:
        trainOut.open("TrainFile.txt", ios::in);
        cout << "Enter train number: ";
        cin >> trainNumber;
        bool found = false;

        while (getline(trainOut, line))
        {
            if (line == ("Train number: " + trainNumber))
            {
                found = true;
                getline(trainOut, y);
                cout << "\n" << y << endl;
                while (getline(trainOut, line))
                {
                    cout << line << endl;
                    if (line == "__________________________")
                        break;
                }
            }
        }

        trainOut.close();

        if (!found)
        {
            cout << "Train not found" << endl;
            system("pause");
            goto retry1;
        }
        else
        {
            return trainNumber + y.substr(14, y.length() - 14);
        }
    }

    void deleteTrain()
    {
        ifstream trainIn("TrainFile.txt");
        cout << "Enter train number: ";
        cin >> trainNumber;

        ofstream tempFile("TempFile.txt");

        bool found = false;
        while (getline(trainIn, line))
        {
            if (line == "Train number: " + trainNumber)
            {
                found = true;
                while (getline(trainIn, line))
                {
                    if (line == "__________________________")
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
            cout << "Train not found in the file." << endl;
        else
        {
            remove("TrainFile.txt");
            rename("TempFile.txt", "TrainFile.txt");
            cout << "Train deleted successfully." << endl;
        }
    }

    void seatBooked(string TrainNumber, int numberOfPassengerOnBooking, int numberOfPassengerOnCancelling)
    {
        trainOut.open("TrainFile.txt", ios::in);
        string old_seat, new_seat;
        int line = 0;

        while (getline(trainOut, y))
        {
            if (y == ("Train number: " + TrainNumber))
            {
                while (getline(trainOut, y))
                {
                    line++;
                    if (line == 3)
                    {
                        old_seat = y;
                        numberOfSeats = to_string(stoi(y.substr(17, y.length() - 17)) - numberOfPassengerOnBooking + numberOfPassengerOnCancelling);
                        new_seat = "Number of seats: " + numberOfSeats;
                    }
                }
            }
        }
        trainOut.close();
        update(old_seat, new_seat);
    }

    int getFare(string TrainNumber)
    {
        trainOut.open("TrainFile.txt", ios::in);
        int line = 0;

        while (getline(trainOut, y))
        {
            if (y == ("Train number: " + TrainNumber))
            {
                while (getline(trainOut, y))
                {
                    line++;
                    if (line == 5)
                    {
                        trainOut.close();
                        return stoi(y.substr(5, y.length() - 5));
                    }
                }
            }
        }
    }
    
    void update(string oldLine, string newLine)
    {
        ifstream trainIn("TrainFile.txt");
        ofstream tempFile("TempFile.txt");

        while (getline(trainIn, line))
            (line == oldLine) ? tempFile << newLine << '\n' : tempFile << line << '\n';

        trainIn.close();
        tempFile.close();
        remove("TrainFile.txt");
        rename("TempFile.txt", "TrainFile.txt");
    }
};

#endif // ADMINISTRATION_H