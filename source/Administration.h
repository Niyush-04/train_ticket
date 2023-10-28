#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TrainManagement
{
private:
    string trainNumber, numberOfSeats, route, timing, fare;
    ofstream trainIn;
    ifstream trainOut;
    void trainData()
    {
        trainIn.open("TrainFile.txt", ios::in | ios::app);
        trainIn << "Train number: " << trainNumber << endl;
        trainIn << "Number of seats: " << numberOfSeats << endl;
        trainIn << "Route: " << route << endl;
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

        cin.ignore(); // Ignore the newline character
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
void searchTrain()
{
retry1:
    trainOut.open("TrainFile.txt", ios::in);
    string search;
    cout << "Enter train number: ";
    cin >> search;
    string y;
    bool found = false;

    while (getline(trainOut, y))
    {
        if (y == ("Train number: " + search))
        {
            found = true;
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
