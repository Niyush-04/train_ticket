#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

class Auth
{
private:
    string username, password, admin;
    ifstream fin;
    ofstream fout;

public:
    bool signup(int type)
    {
        fout.open("login.txt", ios::out | ios::app);
        fin.open("login.txt", ios::in);
    label:
        cout << "Enter username:";
        cin >> username;
        string x;
        while (fin >> x)
        {
            if (x == "Username:" + username)
            {
                cout << "Username already exists";
                goto label;
            }
        }
        cout << "Enter password:";
        cin >> password;
        if (type == 1)
        {
            fout << "Type: admin" << endl;
        }
        else if (type == 2)
        {
            fout << "Type: user" << endl;
        }
        fout << "Username:" << username << endl;
        fout << "Password:" << password << endl
             << endl;
        fout.close();
        fin.close();
        return true;
    }

    bool Login(int type)
    {
        fin.open("login.txt", ios::in);
        cout << "Enter username:";
        cin >> username;
        cout << "Enter password:";
        cin >> password;
        string x;
        string userLine = "Username:" + username;
        string passLine = "Password:" + password;
        string typeLine;
        if (type == 1)
        {
            typeLine = "Type: admin";
        }
        else if (type == 2)
        {
            typeLine = "Type: user";
        }
        while (getline(fin, x))
        {
            if (x == typeLine)
            {
                getline(fin, x);
                if (x == userLine)
                {
                    getline(fin, x);
                    if (x == passLine)
                    {
                        fin.close();
                        return true;
                    }
                }
            }
        }
        fin.close();
        return false;
    }
};

void processUserChoice(int userType) {
    Auth auth;
    int choice;
    cout << "\n";
    cout << "1. Create new account\t";
    cout << "2. Login existing account\t\t";
    cout << "0. EXIT\n" << endl;
    cout << "Input: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "SIGNUP" << endl;
            if (auth.signup(userType)) {
                cout << "Your account has been created successfully" << endl;
                system("pause");
            }
            break;
        case 2:
            cout << "LOGIN" << endl;
            string flag = (userType == 1) ? "admin" : "user";
            retryLogin:
            if (auth.Login(userType)) {
                cout << "Login successful" << endl;
                system("pause");
                flag = (userType == 1) ? "admin" : "user";
            } else {
                cout << "Login failed" << endl;
                system("pause");
                goto retryLogin;
            }
            break;
    }
}
