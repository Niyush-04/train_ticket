#include "source/headers.h"
#include "source/Administration.h"
#include "source/decoration.h"
#include "source/ticketBooking.h"

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

    if (userchoice == 1 || userchoice == 2) {
        processUserChoice(userchoice);
        flag = (userchoice == 1) ? "admin" : "user";
    } else if (userchoice == 0) {
    } else {
        cout << "Invalid choice. Exiting..." << endl;
    }

    char option;
TicketBooking tb;
TrainManagement tm;
// admin
    if (flag == "admin")
    {
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
//for user 
        if (flag == "user")
    {
    retry6:
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
            cout <<"coming soon";
            system("pause");
            goto retry6;
            break;
        case 5:
            cout<<"coming soon";
            system("pause");
            goto retry6;
            break;
        case 6:
            cout<<"coming soon";
            system("pause");
            goto retry6;
            break;
        case 0:
            exit(0);
        }
        
    }
    return 0;
}