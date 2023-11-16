#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TrainManagement
{
public:
    string trainNumber, trainName, trainRoute, numberOfSeats, trainTime, trainFare, line, y;
    // line & y are used to store the data temporarily
    ofstream trainIn;
    ifstream trainOut;

    void trainData()
    {
        trainIn.open("TrainFile.txt", ios::in | ios::app);
        trainIn << "Train number: " << trainNumber << endl;
        trainIn << "Name of train: " << trainName << endl;
        trainIn << "Route: " << trainRoute << endl;
        trainIn << "Number of seats: " << numberOfSeats << endl;
        trainIn << "Timing: " << trainTime << endl;
        trainIn << "Fare: " << trainFare << endl;
        trainIn << "__________________________" << endl;
        trainIn.close();
    }

    void addNewTrain()
    {
        cout << "Enter train number (4 digits): ";
        cin >> trainNumber;

        cin.ignore();

        cout << "Enter train name: ";
        getline(cin, trainName);

        cout << "Enter trainRoute: ";
        getline(cin, trainRoute);

        cout << "Enter timings (eg. 6:00pm-7:00am): ";
        cin >> trainTime;

        cout << "Enter number of seats: ";
        cin >> numberOfSeats;

        cout << "Enter fare: ";
        cin >> trainFare;

        trainData();
    }

    void viewTrains()
    {
        trainOut.open("TrainFile.txt", ios::out);
        while (getline(trainOut, y))
        {
            cout << y << endl;
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
        int i = 0;

        while (getline(trainOut, y))
        {
            if (y == ("Train number: " + TrainNumber))
            {
                while (getline(trainOut, y))
                {
                    i++;
                    if (i == 3)
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
        int i = 0;

        while (getline(trainOut, y))
        {
            if (y == ("Train number: " + TrainNumber))
            {
                while (getline(trainOut, y))
                {
                    i++;
                    if (i == 5)
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

class updateTrain : public TrainManagement
{
public:
    void dataUpdate()
    {
        searchTrain();
        trainOut.open("TrainFile.txt", ios::in);

        while (getline(trainOut, y))
        {
            if (y == ("Train number: " + trainNumber))
            {
                trainNumber = y;

                getline(trainOut, y);
                trainName = y;

                getline(trainOut, y);
                trainRoute = y;

                getline(trainOut, y);
                numberOfSeats = y;

                getline(trainOut, y);
                trainTime = y;

                getline(trainOut, y);
                trainFare = y;
            }
        }
        trainOut.close();
    }

    void updateTrainNumber()
    {
        string newTrainNumber;
        cout << "Enter new train number: ";
        cin >> newTrainNumber;
        update(trainNumber, "Train number: " + newTrainNumber);
    }

    void updateTrainName()
    {
        string newTrainName;
        cout << "Enter new train name: ";
        cin.ignore();
        getline(cin, newTrainName);
        update(trainName, "Train name: " + newTrainName);
        cout << "Train name updated successfully." << endl;
    }

    void updateTrainRoute()
    {
        string newTrainRoute;
        cout << "Enter new train route: ";
        getline(cin, newTrainRoute);
        update(trainRoute, "Train route: " + newTrainRoute);
        cout << "Train route updated successfully." << endl;
    }

    void updateTrainNumberOfSeats()
    {
        string newTrainNumberOfSeats;
        cout << "Enter new number of seats: ";
        cin >> newTrainNumberOfSeats;
        update(numberOfSeats, "Number of seats: " + newTrainNumberOfSeats);
        cout << "Number of seats updated successfully." << endl;
    }

    void updateTrainTime()
    {
        string newTrainTime;
        cout << "Enter new time: ";
        cin >> newTrainTime;
        update(trainTime, "Time: " + newTrainTime);
        cout << "Time updated successfully." << endl;
    }

    void updateTrainFare()
    {
        string newTrainFare;
        cout << "Enter new fare: ";
        cin >> newTrainFare;
        update(trainFare, "Fare: " + newTrainFare);
        cout << "Fare updated successfully." << endl;
    }
};

#endif // ADMINISTRATION_H