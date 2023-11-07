#include <fstream>
#include <string>
#include <stdlib.h>
#include "decoration.h"

string Name;

class Auth
{
private:
    string username, password, admin;
    ifstream fin;
    ofstream fout;

public:
    bool signup(char type)
    {
        fout.open("login.txt", ios::out | ios::app);
        fin.open("login.txt", ios::in);
    label:
        cout << "\nEnter username: ";
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
        cout << "\nEnter password: ";
        cin >> password;
        if (type == '1')
        {
            fout << "Type: admin" << endl;
        }
        else if (type == '2')
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

    bool Login(char type)
    {
        fin.open("login.txt", ios::in);
        cout << "\nEnter username: ";
        cin >> username;
        Name=username;
        cout << "\nEnter password: ";
        cin >> password;
        string x;
        string userLine = "Username:" + username;
        string passLine = "Password:" + password;
        string typeLine;
        if (type == '1')
        {
            typeLine = "Type: admin";
        }
        else if (type == '2')
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

void processUserChoice(char userType) {
    Auth auth;
    retry1:
    char choice;
    cin >> choice;
    printHeader();
    if(choice == '1'){
            cout << "                            -----SIGNUP-----"<<endl;
            cout << "-------------------------------------------------------------------------" << endl;

            if (auth.signup(userType)) {
                cout << "Your account has been created successfully" << endl;
                system("pause");
                exit(0);
            }
    }
    else if(choice == '2'){
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
    else if(choice == '0'){
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

