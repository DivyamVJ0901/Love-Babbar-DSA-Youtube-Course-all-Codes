#include <iostream>
using namespace std;

int main()
{

    int n = 1330;
    int p, r;
    // cout<<"Enter the value of n : "<<endl;
    // cin>>n;

    switch (n)
    {
    case 1330:
        n = n / 100;
        cout << "The no. of 100Rs notes required is : " << n << endl;
        // break;

        n = n % 100;
        return n;

    case 30:
        n = n / 20;
        cout << "The no. of 20Rs notes required is : " << n << endl;
        // break;

        n = n % 20;
        return n;

    case 10:
        cout << "The no. of 1 Rupee notes required is : " << n << endl;
        // break;

    default:
        break;
    }

    return 0;
}