#include "source/Authentication.h"
#include "source/decoration.h"
#include "source/ticketBooking.h"

int main()
{
    TicketBooking tb;
    TrainManagement tm;
    string flag;
    string userchoice;
    loading();
    system("pause");
    loginpage1:
    printHeader();
    loginpage1();
    cin >> userchoice;

    if (userchoice == "1" || userchoice == "2")
    {
        system("cls");
        printHeader();
        loginpage2();
        processUserChoice(userchoice);
        flag = (userchoice == "1") ? "admin" : "user";
    }
    else if (userchoice == "0")
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
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
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
        case 2:
            tm.viewTrains();
            system("pause");
            goto retry3;
            break;
        case 3:
            tm.searchTrain();
            break;
        case 4:
            tb.viewBookings();
            system("pause");
            goto retry3;
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
    // for user
    if (flag == "user")
    {
    retry6:
        printHeader();
        printname();
        userMenu();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            tm.viewTrains();
            system("pause");
            goto retry6;
            break;
        case 2:
            tm.searchTrain();
            system("pause");
            goto retry6;
            break;
        case 3:
            tb.bookTicket();
            system("pause");
            goto retry6;
            break;
        case 4:
            tb.searchBooking();
            system("pause");
            goto retry6;
            break;
        case 5:
            cout << "coming soon";
            system("pause");
            goto retry6;
            break;
        case 6:
            cout << "coming soon";
            system("pause");
            goto retry6;
            break;
        case 0:
            exit(0);
        }
    }
    return 0;
}