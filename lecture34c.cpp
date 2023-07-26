// CODE FOR CALCULATION OF POWER USING RECURSION
#include <iostream>
using namespace std;

int Power(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0)
        return Power(a, b / 2) * Power(a, b / 2);
    else
        return a * Power(a, b / 2) * Power(a, b / 2);
}

int main()
{
    int x, y;
    cout << "Enter the values of x and y : ";
    cin >> x >> y;

    cout << "Your result is : " << Power(x, y);
    return 0;
}