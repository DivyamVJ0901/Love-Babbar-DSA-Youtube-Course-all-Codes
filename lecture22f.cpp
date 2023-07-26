// CODE TO FIND OUT MAXIMUM OCCURING CHARACTER IN A STRING
#include <iostream>
#include <vector>
using namespace std;

char getMaxOccChar(string s)
{
    int arr[26] = {};

    // Create an array of count of characters
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int num = 0;
        num = ch - 'a';
        arr[num]++;
    }

    // Find maximum Occurence character
    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }
    return 'a' + ans;
}
int main()
{
    string s = "Aur bhai , kya haal chaal ??";
    cout<<"Your string is : "<<s<<endl;
    cout<<"The Maximum occuring character in given string is : "<<getMaxOccChar(s);
    return 0;
}