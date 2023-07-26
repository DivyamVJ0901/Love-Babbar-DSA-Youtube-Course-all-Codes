#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string str;
    cout<<"Enter a Non-spaced string : "<<endl;
    cin>>str;

    stack<char> name;

    for (int i = 0; i < str.length(); i++)
        name.push(str[i]);

    string ans = "";
    while (!name.empty())
    {
        ans.push_back(name.top());
        name.pop();
    }
        
    cout<<"The reversed string is : "<<ans<<endl;
    return 0;
}  