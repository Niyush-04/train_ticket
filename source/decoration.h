#ifndef DECORATION_H
#define DECORATION_H
#include <iostream>
using namespace std;

// ANSI color codes
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string BOLD = "\033[1m";

void loading() {
    system("cls");
    cout << RED << "___________   _______________________________________^__" << endl;
    cout << " ___   ___ |||  ___   ___   ___    ___ ___  |   __  ,----\\" << endl;
    cout << "|   | |   |||| |   | |   | |   |  |   |   | |  |  | |_____\\" << endl;
    cout << "|___| |___|||| |___| |___| |___|  | O | O | |  |  |        \\" << endl;
    cout << "           |||                    |___|___| |  |__|         )" << endl;
    cout << "___________|||______________________________|______________/" << endl;
    cout << "           |||                                        /--------" << endl;
    cout << "-----------'''---------------------------------------'" << RESET << endl;
    cout << BOLD << YELLOW << "          Welcome to the Train Booking System!" << endl << endl;
    cout << "Please log in to access your account and book your train tickets." << endl;
    cout << "If you don't have an account yet, you can sign up to create one." << endl;
    cout << "We're here to make your train travel convenient and enjoyable." << endl;
    cout << "Thank you for choosing our services!" << RESET << endl << endl;
}

void printHeader() {
    system("cls");
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << BOLD << "                  -----TRAIN BOOKING TICKET SERVICE----- " << endl;
    cout << "-------------------------------------------------------------------------" << RESET << endl << endl;
    cout << YELLOW << "Welcome to our Train Booking System. Begin your journey with us!" << RESET << endl << endl;
}

void adminMenu() {
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << BOLD << "                         -----ADMIN MAIN MENU-----" << endl;
    cout << "-------------------------------------------------------------------------" << RESET << endl << endl;
    cout << GREEN << "1. Add Train                                    2. Display Trains\n\n";
    cout << "3. Search Trains                                4. Display Bookings\n\n";
    cout << "5. Delete Train                                 6. Update\n\n";
    cout << "0. Logout\n\n" << RESET;
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << "Select an option: ";
}

void userMenu() {
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << BOLD << "                         -----USER MAIN MENU-----" << endl;
    cout << "-------------------------------------------------------------------------" << RESET << endl << endl;
    cout << GREEN << "1. Display Trains                               2. Search Trains\n\n";
    cout << "3. Book Ticket                                  4. Print Ticket\n\n";
    cout << "5. Change Password                              6. Cancel Ticket\n\n";
    cout << "0. Logout\n\n" << RESET;
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << "Select an option: ";
}

void loginpage1() {
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << BOLD << "                         -----LOGIN PAGE-----" << endl;
    cout << "-------------------------------------------------------------------------" << RESET << endl << endl;
    cout << GREEN << "1. Admin\n\n";
    cout << "2. User\n\n";
    cout << "0. Exit\n\n" << RESET;
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << "Select an option: ";
}

void loginpage2() {
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << BOLD << "                         -----LOGIN PAGE-----" << endl;
    cout << "-------------------------------------------------------------------------" << RESET << endl << endl;
    cout << GREEN << "1. Create new account\n\n";
    cout << "2. Login existing account\n\n";
    cout << "0. Exit\n\n" << RESET;
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << "Select an option: ";
}

void seatNumberShow() {
    system("cls");
    cout <<"-------------------------------------------------------------------------" << endl;
    cout << "                         -----SEAT NUMBER-----" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "SL         SU          LB          MB          UB" << endl << endl;
    cout << "01         02          03          04          05"<< endl;
    cout << "06         07          08          09          10" << endl;
    cout << "11         12          13          14          15" << endl;
    cout << "16         17          18          19          20" << endl;
    cout << "21         22          23          24          25" << endl;
    cout << "26         27          28          29          30" << endl;
    cout << "31         32          33          34          35" << endl;
    cout << "36         37          38          39          40" << endl;
    cout << "41         42          43          44          45" << endl;
    cout << "46         47          48          49          50" << endl;
    cout << "51         52          53          54          55" << endl << endl;
    cout << "Choose the seat number: ";
}

void paymentPage(int amount) {
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << BOLD << "                         -----PAYMENT PAGE-----" << endl;
    cout << "-------------------------------------------------------------------------" << RESET << endl << endl;
    cout << BOLD << "Total Amount is Rs. "<< amount<< endl << endl;
    cout << "Choose the mode of payment ... " << endl << endl;
    cout << GREEN << "1. Cash\n\n";
    cout << "2. Card\n\n";
    cout << "3. UPI\n\n" << RESET;
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << "Select an option: ";
}

void passwordMenu(){
    system("cls");
    cout << CYAN << "-------------------------------------------------------------------------" << endl;
    cout << BOLD << "                         -----CHANGE PASSWORD-----" << endl;
    cout << "-------------------------------------------------------------------------" << RESET << endl << endl;
    cout << "Enter your old password: ";
    // cin >> oldPassword;
    // if(oldPassword == password){
    //     cout << "Enter your new password: "<<;
    //     cin >> newPassword;
    //     password = newPassword;
    //     cout << "Password changed successfully." << endl;
    // }
}

#endif