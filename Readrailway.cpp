#include "Railway.h"
int main()
{
    railway R;
    fstream F;
    F.open("rail.db", ios::in | ios::binary);

    while (!F.eof())
    {
        F.read((char *)&R, sizeof(R));
        if (F.eof())
        {
            break;
        }
        cout << endl;
        R.putstation();
    }
}
