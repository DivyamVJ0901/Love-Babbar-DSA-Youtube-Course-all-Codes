// CODE TO CHECK WHETHER A STRING IS PALINDROME OR NOT
#include <iostream>
using namespace std;

char changeCase(char b)
{
    if (b >= 'a' && b <= 'z')
        return b;
    else
        return b - 'A' + 'a';
}

bool checkPalindrome(string str)
{
    int s = 0;
    int e = str.length() - 1;

    while (s <= e)
    {
        if (changeCase(str[s]) == changeCase(str[e]))
            s++, e--;

        else
            return 0;
    }
    return 1;
}

int main()
{
    string str1 = "noon";
    string str2 = "Noon";
    cout << str1 << endl;
    bool ans1 = checkPalindrome(str1);
    if (ans1 == 1)
        cout << "Yes , It's a Palindrome." << endl;
    else
        cout << "No , It's not a Palindrome." << endl;

    cout << str2 << endl;
    bool ans2 = checkPalindrome(str2);
    if (ans2 == 1)
        cout << "Yes , It's a Palindrome." << endl;
    else
        cout << "No , It's not a Palindrome." << endl;

    return 0;
}