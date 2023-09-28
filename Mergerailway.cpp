#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
int ch;
char p;
do
{
system("cls");
cout<<"Main Menu\n1:Add Train\n2:Display\n3:Search\n4:Update\n5:Delete\n6:Exit\n";
cout<<"Enter your choice:";
cin>>ch;
system("cls");
switch(ch)
{
case 1:
system("Insertrailway.exe");
break;
case 2:
system("Readrailway.exe");
break;
case 3:
system("Searchbytrainno.exe");
break;
case 4:
system("Updatetrain.exe");
break;
case 5:
system("Deletetrain.exe");
break;
case 6:
cout<<"Good bye....."<<endl;
break;
default:
cout<<"Wrong option"<<endl;
}
cout<<"\n\nPress any key to continue....."<<endl;
cin.ignore();
cin.get();
}while(ch!=6);
}
