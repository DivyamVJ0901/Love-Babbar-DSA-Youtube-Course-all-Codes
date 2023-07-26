#include <iostream>
using namespace std;

int fact(int n)
{

    if (n == 1 || n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int nCr(int n, int r)
{

    // int r;
    if (r == n)
    {
        return 1;
    }
    else if (r > n)
    {
        cout << "Not possible" << endl;
    }
    else
    {
        int a = fact(n);
        int b = fact(r);
        int c = fact(n - r);
        return a / (b * c);
    }
}

int main()
{
    int n, r;
    cout << "Enter the value of n: " << endl;
    cin >> n;

    cout << "Enter the value of r : " << endl;
    cin >> r;

    cout << "The value of factorial of entered number is : " << fact(n) << endl;
    cout << "The value of factorial of second entered number is : " << fact(r) << endl;
    cout << "The value of nCr is : " << nCr(n, r) << endl;

    return 0;
}