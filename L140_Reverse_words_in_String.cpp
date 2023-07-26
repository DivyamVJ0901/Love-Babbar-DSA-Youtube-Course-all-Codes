#include <bits/stdc++.h>
using namespace std;

string reversed(string s)
{
    string ans = "";
    string temp = "";

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            reverse(temp.begin(), temp.end());
            ans += temp;
            temp = "";
            ans.push_back(' ');
        }
        else
            temp.push_back(s[i]);
    }
    reverse(temp.begin(), temp.end());
    ans += temp;
    return ans;
}

int main()
{
    string ques = "my   name   is   divyam   vijay";
    cout<<reversed(ques);
    return 0;
}