#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

string Name;

class Auth
{
private:
    string username, password, admin;
    ifstream fin;
    ofstream fout;

public:
    bool signup(string type)
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
        if (type == "1")
        {
            fout << "Type: admin" << endl;
        }
        else if (type == "2")
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

    bool Login(string type)
    {
        fin.open("login.txt", ios::in);
        cout << "Enter username:";
        cin >> username;
        Name=username;
        cout << "Enter password:";
        cin >> password;
        string x;
        string userLine = "Username:" + username;
        string passLine = "Password:" + password;
        string typeLine;
        if (type == "1")
        {
            typeLine = "Type: admin";
        }
        else if (type == "2")
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
    }
};

void printname(){
    cout<<"Hello "<<Name<<", Welcome back!"<<endl;
}

void processUserChoice(string userType) {
    Auth auth;
    retry1:
    string choice;
    cin >> choice;

    if(choice == "1"){
            cout << "                            -----SIGNUP-----"<<endl;
            cout << "-------------------------------------------------------------------------" << endl;

            if (auth.signup(userType)) {
                cout << "Your account has been created successfully" << endl;
                system("pause");
                exit(0);
            }
    }
    else if(choice == "2"){
            cout << "                            -----LOGIN-----"<<endl;
            cout << "-------------------------------------------------------------------------" << endl;
            retryLogin:
            if (auth.Login(userType)) {
                cout << "Login successful" << endl;
                system("pause");
            } else {
                cout << "Login failed" << endl;
                system("pause");
                goto retryLogin;
            }
    }
    else if(choice == "0"){
        cout<<"Thanks for reaching out !!";
        exit(0);
    }
    else{
        cout<<"Invalid input"<<endl;
       system("pause");
       cout<<"\nSelect an option: ";
        goto retry1;
    }
}

