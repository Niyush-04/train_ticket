#include <iostream>
#include <fstream>
using namespace std;
class railway
{
private:
    int R, E;
    char name[100], S[50], H[50], P[50], J[50];

public:
    void getstation()
    {
        cout << "Enter Train Number:";
        cin >> R;
        cout << "Enter Train name:";
        fflush(stdin);
        cin.getline(name, 50);
        cout << "Enter Train Source Station:";
        fflush(stdin);
        cin.getline(S, 50);
        cout << "Enter Train Destination station:";
        fflush(stdin);
        cin.getline(H, 50);
        cout << "Enter Train Total seats:";
        cin >> E;
        cout << "Enter Train Departure time and date:";
        fflush(stdin);
        cin.getline(P, 50);
        cout << "Enter Train Destination Station reach time and date:";
        fflush(stdin);
        cin.getline(J, 50);
    }

    void putstation()
    {
        cout << "\t\t\t\t\tTRAIN INFORMATION\n";
        cout << "\t----------------------------------------------------------------------------------\n";
        cout << "\n\tTrain Number:" << R << "\t\t\t\n";
        cout << "\tTrain Name:" << name << "\t\t\t\n";
        cout << "\tSource Station Name:" << S << "\t\t\t\n";
        cout << "\tDestination Station Name:" << H << "\t\t\t\n";
        cout << "\tTrain Total seats:" << E << "\t\t\t\n";
        cout << "\tTrain Departure Time and Date:" << P << "\t\t\t\n";
        cout << "\tTrain Destination Station reach Time and Date:" << J << "\t\t\t\n";
        cout << "\t--------------------------------------------------------------------------------------\n";
    }
    int searchBYTRAINNO(int Z)
    {
        if (Z == R)
        {
            return 1;
        }
        return 0;
    }
    void updatetrain()
    {
        int v;
        cout << "Train details...... " << endl;
        cout << "Train Number:" << R << endl;
        cout << "1-Train Name:" << name << endl;
        cout << "2-Source Station Name:" << S << endl;
        ;
        cout << "3-Destination Station Name:" << H << endl;
        cout << "4-Train Total seats:" << E << endl;
        cout << "5-Train Departure time and date:" << P << endl;
        cout << "6-Train Destination Station reach time and date:" << J << endl;
        cout << "Which detail you want to edit:";
        cin >> v;
        switch (v)
        {
        case 1:
            cout << "Enter New Train Name:";
            cin >> name;
            break;
        case 2:
            cout << "Enter New Source Station Name:";
            cin >> S;
            break;
        case 3:
            cout << "Enter New Destination Station Name:";
            cin >> H;
            break;
        case 4:
            cout << "Enter New Train Total seats:";
            cin >> E;
            break;
        case 5:
            cout << "Enter New Train Departure time and date:";
            cin >> P;
            break;
        case 6:
            cout << "Enter New Train Destination Station reach time and date:";
            cin >> J;
            break;
            break;
        default:
            cout << "Wrong option......" << endl;
            break;
        }
    }
};
