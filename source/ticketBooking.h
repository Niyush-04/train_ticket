#include<iostream>
#include<fstream>
#include<string.h>
#include <ctime>
#include "Administration.h"
using namespace std;


class TicketBooking : public TrainManagement{
	private:
		string trainNo,nameOfPassenger,numberOfTickes,seatNumbers, boardingStation, timing, fare , trainInfo;
		ifstream fin;
		ofstream fout;
		int tin;
		void storeInFile(){
			fout.open("Tickets.txt",ios::in|ios::app);
			fin.open("TrainFile.txt",ios::out);
			fout<<"Train : "<<trainInfo<<endl;
			fout<<"Ticket inquiry number: "<<tin<<endl;
			fout<<"Passenger name: "<<nameOfPassenger<<endl;
			fout<<"Number of tickets: "<<numberOfTickes<<endl;
			fout<<"_______________"<<endl;
			fout.close();
			fin.close();
		}
	public:
		void bookTicket(){
			srand(time(0));
			tin=rand()% 9000 + 1000;  //train inquiry number
			trainInfo = searchTrain();
			cout<<"Train : "<<trainInfo<<endl;
			cout<<"Ticket inquiry number: "<<tin<<endl;
			cout<<"Enter name of passenger: ";
			cin.ignore();
			getline(cin,nameOfPassenger);
			cout<<"Enter number of tickets: ";
			cin>>numberOfTickes;
			label:
			cout<<"Boarding Station: ";
			cin>>boardingStation;
			storeInFile();
		}
		void viewBookings(){
			fin.open("Tickets.txt",ios::out);
			string x;
			while(getline(fin,x)){
				cout<<x<<endl;
			}
			fin.close();
		}
			void searchBooking(){
			fin.open("Tickets.txt",ios::out);
			string search;
			cout<<"Enter TIN search: ";
			cin>>search;
			string y;
			while(getline(fin,y)){
				if(y==("Booking id: "+search)){
					while(getline(fin,y)){
						cout<<"\t\t\t"<<y<<endl;
						if(y=="_______________"){
							break;
						}
					}
				}
			}
			fin.close();
		}
};
