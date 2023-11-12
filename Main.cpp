#include "source/Authentication.h"
#include "source/ticketBooking.h"

int main()
{
    TicketBooking tb;
    TrainManagement tm;
    Auth log;
    string flag;
    char userchoice;
    loading();
    system("pause");
    loginpage1:
    printHeader();
    loginpage1();
    cin >> userchoice;

    if (userchoice == '1' || userchoice == '2')
    {
        system("cls");
        printHeader();
        loginpage2();
        processUserChoice(userchoice);
        flag = (userchoice == '1') ? "admin" : "user";
    }
    else if (userchoice == '0')
    {
        exit(0);
    }
    else
    {
        cout << "Invalid choice. Exiting..." << endl;
        system("pause");
        goto loginpage1;
    }
    // admin
    if (flag == "admin")
    {
    retry3:
        printHeader();
        printname();
        adminMenu();
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1': //add train
        retry4:
            tm.addNewTrain();
            char option;
            cout << "Do you want to add more?(y/n)";
            cin >> option;
            if (option == 'y' || option == 'Y')
            {
                goto retry4;
            }
            else
                goto retry3;
            break;
        case '2': //display train
            tm.viewTrains();
            system("pause");
            goto retry3;
            break;
        case '3': //search train
            tm.searchTrain();
            system("pause");
            goto retry3;
            break;
        case '4': //display bookings
            tb.viewBookings();
            system("pause");
            goto retry3;
            break;
        case '5': //delete train
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
        case '6': //update train
            cout << "coming soon";
            system("pause");
            goto retry3;
        case '0': //logout
            exit(0);
        default:
            cout << "Invalid choice...." << endl;
            system("pause");
            goto retry3;
        }
    }
    // for user
    if (flag == "user")
    {
    retry6:
        printHeader();
        printname();
        userMenu();
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1': //display train
            tm.viewTrains();
            system("pause");
            goto retry6;
            break;
        case '2': //search train
            tm.searchTrain();
            system("pause");
            goto retry6;
            break;
        case '3': //book ticket
            tb.bookTicket();
            system("pause");
            goto retry6;
            break;
        case '4': //print ticket
            tb.searchBooking();
            system("pause");
            goto retry6;
            break;
        case '5': //change password
            bool flag;
            flag = changePassword();
            if(flag) {
                cout << "\n\t\tPassword changed successfully" << endl << endl;
                cout << "\t\tLogin again ..." << endl <<endl;
                exit(0);
            }else {
                cout << "Password not changed" << endl;
                system("pause");
                goto retry6;
            }
            break;
        case '6': //cancel ticket
            tb.cancelTicket();
            system("pause");
            goto retry6;
            break;
        case '0': //logout
            exit(0);
        default:
            cout << "Invalid choice...." << endl;
            system("pause");
            goto retry6;
        }
    }
    return 0;
}