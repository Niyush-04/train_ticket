#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Operations
{
    string route;
    string timing;
    string fare;
};

class TrainManagement
{
private:
    string trainNumber, numberOfSeats;
    Operations operation;
    ofstream trainIn;
    ifstream trainOut;
    void trainData()
    {
        trainIn.open("TrainFile.txt", ios::in | ios::app);
        trainIn << "Train number: " << trainNumber << endl;
        trainIn << "Number of seats: " << numberOfSeats << endl;
        trainIn << "Route: " << operation.route << endl;
        trainIn << "Timing: " << operation.timing << endl;
        trainIn << "Fare: " << operation.fare << endl;
        trainIn << "__________________________" << endl;
        trainIn.close();
    }

public:
    void addNewTrain()
    {
        cout << "Enter train number: ";
        cin >> trainNumber;
        cout << "Enter route: ";
        cin >> operation.route;
        cout << "Enter number of seats: ";
        cin >> numberOfSeats;
        cout << "Enter timings: ";
        cin >> operation.timing;
        cout << "Enter fare: ";
        cin >> operation.fare;
        trainData();
    }
    void viewTrains()
    {
        trainOut.open("TrainFile.txt", ios::out);
        string x;
        while (getline(trainOut, x))
        {
            cout << "\t\t\t" << x << endl;
        }
        trainOut.close();
    }
    void searchTrain()
    {
        retry1:
        trainOut.open("TrainFile.txt", ios::out);
        string search;
        cout << "Enter train number: ";
        cin >> search;
        string y;
        while (getline(trainOut, y))
        {
            if (y == ("Train number: " + search))
            {
                while (getline(trainOut, y))
                {
                    cout << y << endl;
                    if (y == "__________________________")
                        break;
                }
            }
            else
            {
                cout << "Train not found" << endl;
                trainOut.close();
                goto retry1;
            }
        }
        trainOut.close();
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
