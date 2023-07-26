#include <iostream>
#include <stack>
using namespace std;

bool isBalancedParenthesis(string &s)
{
    stack<char> Bracket;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
            Bracket.push(s[i]);
        else
        {
            if (!Bracket.empty())
            {
                char ch = Bracket.top();
                if (((s[i] == ')') && (ch == '(')) || ((s[i] == '}') && (ch == '{')) || ((s[i] == ']') && (ch == '[')))
                    Bracket.pop();
                else
                    return false;
            }
        }
    }
    if (Bracket.empty())
        return true;
    else
        return false;
}

int main()
{
    string temp = "[{({[]})}]";
    cout << "The question is : " << temp << endl;
    if (isBalancedParenthesis(temp))
        cout << "Yup Yup" << endl;
    else
        cout << "Nope Nope" << endl;

    return 0;
}