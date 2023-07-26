#include <iostream>
#include <stack>
using namespace std;

bool isReductant(string &str)
{
    stack<char> Vijay;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            Vijay.push(str[i]);
        else
        {
            if (str[i] == ')')
            {
                bool red = true;
                while (Vijay.top() != '(')
                {
                    if (Vijay.top() == '+' || Vijay.top() == '-' || Vijay.top() == '*' || Vijay.top() == '/')
                        red = false;
                    Vijay.pop();
                }
                if (red == true)
                    return true;
                Vijay.pop();
            }
        }
    }
    return false;
}

void PrintStack(stack<char> &st)
{
    while (!st.empty())
    {
        cout << st.top() << "";
        st.pop();
    }
    cout << endl;
}

int main()
{
    string Divyam = "a + (b * c)";
    cout << Divyam << endl;
    bool ans = isReductant(Divyam);
    if (ans)
        cout << "Yup Yup";
    else
        cout << "Nope Nope";
    return 0;
}