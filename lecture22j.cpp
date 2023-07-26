// CODE TO REMOVE ADJACENT IN DUPLICATES
#include <iostream>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

string replaceDuplicates(string s)
{
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (temp.length() > 0 && temp.back() == s[i])
            temp.pop_back();
        else
            temp.push_back(s[i]);
    }
    return temp;
}

int main()
{
    string s = "azxxzb";
    cout<<"The string is : "<<s<<endl;
    cout <<"The updated string is : "<< replaceDuplicates(s);
    return 0;
}
