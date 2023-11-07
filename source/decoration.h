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

#endif