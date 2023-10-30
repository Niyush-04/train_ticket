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
            cout<< x << endl;
        }
        trainOut.close();
    }
string searchTrain()
{
retry1:
    trainOut.open("TrainFile.txt", ios::in);
    string search;
    cout << "Enter train number: ";
    cin >> search;
    string y;
    string z;
    bool found = false;

    while (getline(trainOut, y))
    {
        if (y == ("Train number: " + search))
        {
            found = true;
            getline(trainOut, z);
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
        goto retry1;
    }
    return search + z.substr(14, z.length() - 14);
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
};

#endif // ADMINISTRATION_H
