#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Auth
{
private:
    string username, password, admin;
    ifstream fin;
    ofstream fout;

public:
    bool signup()
    {
        fout.open("login.txt", ios::out | ios::app);
        fin.open("login.txt", ios::in);
        cout << "Enter name of admin:";
        cin >> admin;
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
        fout << "Admin name:" << admin << endl;
        fout << "Username:" << username << endl;
        fout << "Password:" << password << endl;
        fout.close();
        fin.close();
        return true;
    }

    bool Login()
    {
        fin.open("login.txt", ios::in);
        cout << "Enter username:";
        cin >> username;
        cout << "Enter password:";
        cin >> password;
        string x;
        string userLine = "Username:" + username;
        string passLine = "Password:" + password;
        while (getline(fin, x))
        {
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
        fin.close();
        return false;
    }
};