// CODE TO CHECK WHETHER A STRING IS VALID PALINDROME OR NOT
#include <iostream>
#include <vector>
using namespace std;

bool validChar(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return 1;
    else
        return 0;
}

char changeCase(char b)
{
    if (b >= 'a' && b <= 'z')
        return b;
    else
        return b - 'A' + 'a';
}

bool checkPalindrome(string a)
{
    int s = 0;
    int e = a.length() - 1;

    while (s <= e)
    {
        if (a[s] == (a[e]))
        {
            s++;
            e--;
        }
        else
            return 0;
    }
    return 1;
}

bool isPalindrome(string s)
{
    // Faltu character hatado by using validChar function
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (validChar(s[i]))
            temp.push_back(s[i]);
    }
    // Capital letter ko small me convert kardo by using changeCase function

    for (int i = 0; i < temp.length(); i++)
        temp[i] = changeCase(temp[i]);

    // check a valid Palindrome or not
    return checkPalindrome(temp);
}

int main()
{
    string line;
    cout << "Enter any line : ";
    cin >> line;
    cout << "The entered line is : " << line << endl;
    cout << "The length of entered line is : " << line.length() << endl;
    bool ans = isPalindrome(line);
    if (ans == 1)
        cout << "Yes , It is a valid Palindrome.";
    else
        cout << "No , it is not a valid Palindrome.";

    return 0;
}