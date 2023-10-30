#include<iostream>
using namespace std;
void loading()
{
    system("cls");
    cout << "___________   _______________________________________^__" << endl;
    cout << " ___   ___ |||  ___   ___   ___    ___ ___  |   __  ,----\\" << endl;
    cout << "|   | |   |||| |   | |   | |   |  |   |   | |  |  | |_____\\" << endl;
    cout << "|___| |___|||| |___| |___| |___|  | O | O | |  |  |        \\" << endl;
    cout << "           |||                    |___|___| |  |__|         )" << endl;
    cout << "___________|||______________________________|______________/" << endl;
    cout << "           |||                                        /--------" << endl;
    cout << "-----------'''---------------------------------------'" << endl;
}

void printHeader()
{
    system("cls");
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "                  -----TRAIN BOOKING TICKET SERVICE----- " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "" << endl;
}

void adminMenu(){
    printHeader();
    cout << "\n----------------------------------MENU----------------------------------\n"
             << endl;
        cout << "1. Add Train\t\t\t";
        cout << "2. Display Trains\t\t\t\n\n";
        cout << "3. Search Trains\t\t";
        cout << "4. Display Bookings\t\t";
        cout << "5. Delete Train\t\t\t\n\n";
        cout << "6. Update\t\t\t";
        cout << "0. Logout\t\t\t\n\n";
        cout << "---------------------------------------------------------------------------\n"
             << endl;
}

void userMenu(){
    printHeader();
    cout << "\n----------------------------------MENU----------------------------------\n"
             << endl;
        cout << "1. Display\t\t\t";
        cout << "2. Search Trains\t\t\t\n\n";
        cout << "3. Book Ticket\t\t";
        cout << "4. Print Ticket\t\t";
        cout << "5. change password\t\t\t\n\n";
        cout << "6. Cancell Ticket\t\t\t";
        cout << "0. Logout\t\t\t\n\n";
        cout << "---------------------------------------------------------------------------\n"
             << endl;
}
