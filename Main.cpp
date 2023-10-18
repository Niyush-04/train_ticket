#include <iostream>
#include <stdlib.h>
#include "headers.h"
#include "decoration.h"
using namespace std;

int main()
{   
    loading();
    system("pause");
    printHeader();

    cout << "Welcome to the Train Booking Ticket Service!\n"<< endl;
    bool flag = false;
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
                flag=true;
            }
            break;
    }

if(flag){
    MainMenu();
    int choice;
    cin>>choice;
    switch(choice){
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
            exit(0);
            }
        }
        return 0;
}