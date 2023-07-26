#include <iostream>
#include <stack>
using namespace std;

int MinBracesReversal(string &str)
{
    if (str.length() % 2 == 1)
        return -1;

    stack<char> cheems;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
            cheems.push(str[i]);
        else
        {
            if (!cheems.empty() && cheems.top() == '{')
                cheems.pop();
            else
                cheems.push(str[i]);
        }
    }

    int a = 0, b = 0;
    while (!cheems.empty())
    {
        if (cheems.top() == '{')
            b++;
        else
            a++;
        cheems.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main()
{
    string vmro = "{{{}";
    cout << MinBracesReversal(vmro);
    return 0;
}