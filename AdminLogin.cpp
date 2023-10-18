#include <iostream>
#include <stdlib.h>
using namespace std;

void printHeader()
{
    system("cls");
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "                  -----TRAIN BOOKING TICKET SERVICE----- " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "" << endl;
}
int main()
{
    int choice;
    char p;
    system("cls");
    printHeader();

    do
    {
        cout << "\n----------------------------------MENU----------------------------------\n"
             << endl;
        cout << "1. Add Train\t\t\t";
        cout << "2. Display\t\t\t\n\n";
        cout << "3. Search Trains\t\t";
        cout << "4. Update\t\t\t\n\n";
        cout << "5. Delete Train\t\t\t";
        cout << "0. Logout\t\t\t\n\n";
        cout << "---------------------------------------------------------------------------\n"
             << endl;
        cout << "Input: ";
        cin >> choice;

        system("cls");
        switch (choice)
        {
        case 1:
            system("Insertrailway.exe");
            break;
        case 2:
            system("Readrailway.exe");
            break;
        case 3:
            system("Searchbytrainno.exe");
            break;
        case 4:
            system("Updatetrain.exe");
            break;
        case 5:
            system("Deletetrain.exe");
            break;
        case 0:
            cout << "Good bye....." << endl;
            break;
        default:
            cout << "Wrong option" << endl;
        }
        cout << "\n\nPress any key to continue....." << endl;
        cin.ignore();
        cin.get();
    } while (choice != 5);
}
