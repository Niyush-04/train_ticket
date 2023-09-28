#include"Railway.h"
int main()
{
railway R;
fstream F;
F.open("rail.db",ios::out|ios::app|ios::binary);

char ch;
do
{
R.getstation();
F.write((char*)&R,sizeof(R));
cout<<"Do you want to add more Train(y/n)?";
cin>>ch;
}while(ch=='y'||ch=='Y');
F.close();
}
