#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TrainManagement
{
private:
    string trainNumber, numberOfSeats, nameOfTrain, route, timing, fare;
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
        cout << "Enter train number: ";
        cin >> trainNumber;

        cin.ignore();

        cout << "Enter train name: ";
        getline(cin, nameOfTrain);

        cout << "Enter route: ";
        getline(cin, route);

        cout << "Enter timings: ";
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
        string search, y, z;
        cout << "Enter train number: ";
        cin >> search;
        bool found = false;

        while (getline(trainOut, y))
        {
            if (y == ("Train number: " + search))
            {
                found = true;
                getline(trainOut, z);
                cout << "\n" << z << endl;
                while (getline(trainOut, y))
                {
                    cout << y << endl;
                    if (y == "__________________________")
                        break;
                }
            }
        }

        trainOut.close();

        if (!found)
        {
            cout << "Train not found" << endl;
        } 
        else {
        return search + z.substr(14, z.length() - 14);
        }
        return "";
    }

    void deleteTrain()
    {
        ifstream trainIn("TrainFile.txt");
        string search;
        cout << "Enter train number: ";
        cin >> search;

        string line;
        ofstream tempFile("TempFile.txt");

        bool found = false;
        while (getline(trainIn, line))
        {
            if (line == "Train number: " + search)
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
    void seatBooked(string TrainNumber)
    {
        trainOut.open("TrainFile.txt", ios::in);
        string old_seat, new_seat, y, seat;
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
                        seat = (to_string)(stoi(y.substr(17, y.length() - 17)) - 1);
                        new_seat = "Number of seats: " + seat;
                    }
                }
            }
        }
        trainOut.close();
        update(old_seat, new_seat);
    }

    void update(string oldLine, string newLine)
    {
        ifstream trainIn("TrainFile.txt");
        string line;
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
