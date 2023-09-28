#include"Railway.h"
#include<stdlib.h>
int main()
{
railway R;
fstream F,T;
int Z,found=0,k=0;
F.open("rail.db",ios::in|ios::binary);
T.open("temp.db",ios::out|ios::binary);
cout<<"Enter Train Number you want to delete:";
cin>>Z;
while(!F.eof())
{
F.read((char*)&R,sizeof(R));
if(F.eof())
{
break;
}
found=R.searchBYTRAINNO(Z);
if(found==0)
{
T.write((char*)&R,sizeof(R));
}
if(found==1)
{
k=1;
}
}
F.close();
T.close();
if(k==0)
{
cout<<"Train not found.....";
}
else
{
remove("rail.db");
rename("temp.db","rail.db");
cout<<endl;
cout<<"Train delete successfully....."<<endl;
}
}

