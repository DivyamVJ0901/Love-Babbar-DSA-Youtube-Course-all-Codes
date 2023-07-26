// CODE TO CONVERT DIGITS INTO WORDS
#include <iostream>
using namespace std;

void SayDigits(int n, string arr[])
{
    if (n == 0)
        return;
    int digit = n % 10;
    n = n / 10;
    SayDigits(n, arr);
    cout << arr[digit] << " ";
}

int main()
{
    int a;
    cin >> a;

    string Divyam[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    SayDigits(a, Divyam);

    return 0;
}