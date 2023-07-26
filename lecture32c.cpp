// CODE TO CONVERT DIGITS INTO WORDS
#include <iostream>
using namespace std;

void SayDigits(int n, string arr[])
{
    int digit;
    if (n == 0)
    {
        return;
    }
    digit = n % 10;
    n = n / 10;
    SayDigits(n, arr);
    cout << arr[digit] << " ";
}

int main()
{
    int a;
    cin >> a;

    string Divyam[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    SayDigits(a, Divyam);

    return 0;
}