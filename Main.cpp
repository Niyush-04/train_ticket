#include <iostream>
#include <stdlib.h>
#include "source/headers.h"
#include "source/Administration.h"
#include "source/decoration.h"
using namespace std;

int main()
{
    loading();
    system("pause");
    printHeader();

    cout << "Welcome to the Train Booking Ticket Service!\n"
         << endl;
    string flag;
    int userchoice;
    cout << "Login as a ..." << endl;
    cout << "1.Admin\n";
    cout << "2.User\n";
    cin >> userchoice;

    Auth auth;
    // login for admin
    if (userchoice == 1)
    {
        int choice;
        cout << "\n";
        cout << "1. Create new account\t";
        cout << "2. Login existing account\t\t";
        cout << "0. EXIT\n"
             << endl;
        cout << "Input: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "SIGNUP" << endl;
            if (auth.signup(1))
            {
                cout << "Your account has been created successfully" << endl;
                system("pause");
            }
            break;
        case 2:
            cout << "LOGIN" << endl;
        retry1:
            if (auth.Login(1))
            {
                cout << "Login successfull" << endl;
                system("pause");
                flag = "admin";
            }
            else
            {
                cout << "Login failed" << endl;
                system("pause");
                goto retry1;
            }
            break;
        }
    }
    // login for user
    if (userchoice == 2)
    {
        int choice;
        cout << "\n";
        cout << "1. Create new account\t";
        cout << "2. Login existing account\t\t";
        cout << "0. EXIT\n"
             << endl;
        cout << "Input: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "SIGNUP" << endl;
            if (auth.signup(2))
            {
                cout << "Your account has been created successfully" << endl;
                system("pause");
            }
            break;
        case 2:
            cout << "LOGIN" << endl;
        retry2:
            if (auth.Login(2))
            {
                cout << "Login successfull" << endl;
                flag = "user";
                system("pause");
            }
            else
            {
                cout << "Login failed" << endl;
                system("pause");
                goto retry2;
            }
            break;
        }
    }

    char option;
    if (flag == "admin")
    {
        TrainManagement tm;
    retry3:
        adminMenu();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        retry4:
            tm.addNewTrain();
            cout << "Do you want to add more?(y/n)";
            cin >> option;
            if (option == 'y' || option == 'Y')
            {
                goto retry4;
            }
            else
                goto retry3;
            break;
        case 2:
            tm.viewTrains();
            system("pause");
            goto retry3;
            break;
        case 3:
            tm.searchTrain();
            break;
        case 4:
            cout << "coming soon";
            system("pause");
            break;
        case 5:
        retry5:
            tm.deleteTrain();
                        cout << "Do you want to delete more?(y/n)";
            cin >> option;
            if (option == 'y' || option == 'Y')
            {
                goto retry5;
            }
            else
                goto retry3;
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}