#include <iostream>
#include <stdlib.h>
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

int adminLogin()
{
retry:
    string login, pass;
    string loginname = "admin";
    string loginpass = "admin123";
    cout << "\n-------------------------------------------------------------------------" << endl;
    cout << "----------------------------------ADMIN----------------------------------\n"
         << endl;
    cout << "Enter your LoginID : ";
    cin >> login;
    cout << "\nEnter Password : ";
    cin >> pass;
    if (loginname == login && loginpass == pass)
    {
        system("Adminlogin.exe");
    }
    else
    {
        cout << "Given LoginID or Password is incorrect. Please try again !!" << endl;
        system("pause");

        goto retry;
    }
}

void userlogin()
{
    cout << "coming soon !! ";
}

int main()
{
    loading();
    system("pause");
    printHeader();

    cout << "Welcome to the Train Booking Ticket Service!\n"
         << endl;
    cout << "You are a Admin/user:" << endl;

    int choice;
    cout << "\n";
    cout << "1. ADMIN\t";
    cout << "2. USER\t\t";
    cout << "0. EXIT\n"
         << endl;
    cout << "Input: ";
    cin >> choice;
    if (choice == 1)
    {
        adminLogin();
    }
    else if (choice == 2)
    {
        userlogin();
    }
    else
        return 0;
}