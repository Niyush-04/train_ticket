#include <iostream>
#include <stdlib.h>
#include "headers.h"
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
int main()
{   
    loading();
    system("pause");
    printHeader();

    cout << "Welcome to the Train Booking Ticket Service!\n"
         << endl;

    int choice;
    cout << "\n";
    cout << "1. Create new account\t";
    cout << "2. Login existing account\t\t";
    cout << "0. EXIT\n"<< endl;
    cout << "Input: ";
    cin >> choice;
    
    Auth auth;
switch(choice){
        case 1:
        cout<<"SIGNUP"<<endl;
			if(auth.signup()){
				cout<<"Your account has been created successfully"<<endl;
				system("pause");
			}
			break;
        case 2:
        cout<<"LOGIN"<<endl;
        
            if(auth.Login()){
                cout<<"Login successfull"<<endl;
                system("pause");
                system("Adminlogin.exe");

            }
            break;
    }
        return 0;
}