#include "Railway.h"
int main()
{
    railway R;
    fstream F;
    int Z, found = 0;
    F.open("rail.db", ios::in | ios::binary);
    cout << "Enter Train number you want to search:";
    cin >> Z;
    while (!F.eof())
    {
        F.read((char *)&R, sizeof(R));
        if (F.eof())
        {
            break;
        }
        found = R.searchBYTRAINNO(Z);
        if (found == 1)
        {
            cout << endl;
            R.putstation();
            break;
        }
    }

    if (found == 0)
    {
        cout << endl;
        cout << "Record not found of these Train.....";
    }
    F.close();
}
