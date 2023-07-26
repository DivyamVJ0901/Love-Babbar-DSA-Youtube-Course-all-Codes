// CODE TO PRINT A FIBONACCI SERIES 
#include <iostream>
using namespace std;

int Fib(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2 || n == 3)
        return 1;
    return Fib(n - 1) + Fib(n - 2);
}

void SayDigits(int n, string arr[])
{
    int digit;
    if (n == 0)
    {
        return;
    }
    digit = n % 10;
    n = n / 10;
    SayDigits(n , arr);
    cout << arr[digit]<<" ";
}
int main()
{
    int a;
    cin >> a;
    cout << "The " << a << "th term of Fibonacci series is ";
    cout << Fib(a) << endl;

 
    return 0;
}
