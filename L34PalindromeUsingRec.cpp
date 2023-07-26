// CODE TO CHECK A PALINDROME USING RECURSION
#include <iostream>
using namespace std;

bool checkPalindrome(string str, int i, int j)
{
    if (i > j)
        return true;

    if (str[i] != str[j])
        return false;

    return checkPalindrome(str, i + 1, j - 1);
}

int main()
{
    string name = "aubbua";
    if (checkPalindrome(name, 0, name.length() - 1))
        cout << "Yes , its a palindrome." << endl;
    else
        cout << "No , its not a palindrome." << endl;
    return 0;
}