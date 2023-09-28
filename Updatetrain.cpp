#include"Railway.h"
#include<stdlib.h>
int main()
{
railway R;
fstream F,T;
int Z,found=0,k=0;
F.open("rail.db",ios::in|ios::binary);
T.open("temp.db",ios::out|ios::binary);
cout<<"Enter Train Number you want to edit:";
cin>>Z;
while(!F.eof())
{
F.read((char*)&R,sizeof(R));
if(F.eof())
{
break;
}
found=R.searchBYTRAINNO(Z);
if(found==1)
{
cout<<endl;
R.updatetrain();
k=1;
}
T.write((char*)&R,sizeof(R));
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
cout<<"Train update successfully....."<<endl;
}
}

