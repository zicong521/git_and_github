#include <iostream>
#include <cmath>
using namespace std;

void TwoToPower(int n)
{

    if (n > 4)
    {
        int i = 0;
        int temp1, temp2;
        while (1)
        {
            temp1 = (int)pow(2, i);
            temp2 = (int)pow(2, i + 1);
            if (temp1 <= n && temp2 > n)
            {
                break;
            }
            else
            {
                ++i;
            }
        }

        cout << "2(";
        TwoToPower(i);
        cout << ")";
        n = n - temp1;
        if (n > 0)
        {
            cout << "+";
            TwoToPower(n);

        }
        else
        {
            return;
        }
    }
    else
    {
        switch (n)
        {
        case 0:
            return;
        case 1:
            cout << "2(0)";
            break;
        case 2:
            cout << '2';
            break;
        case 3:
            cout << "2+2(0)";
            break;
        case 4:
            cout << "2(2)";
            break;
        }
    }
}
int main()
{
    int num;
    cin >> num;
    TwoToPower(num);
    return 0;
}