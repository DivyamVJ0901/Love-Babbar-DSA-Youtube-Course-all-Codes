#include <iostream>
#include <stack>
using namespace std;

// ITERATIVE APPROACH
stack<int> ReverseStack1(stack<int> &st)
{
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    return temp;
}

// RECURSIVE APPROACH
void InsertAtBottom(stack<int> &stack, int x)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }

    int num = stack.top();
    stack.pop();

    InsertAtBottom(stack, x);
    stack.push(num);
}

void ReverseStack2(stack<int> &st)
{
    if (st.empty())
        return;

    int num = st.top();
    st.pop();

    ReverseStack2(st);
    InsertAtBottom(st, num);
}

void PrintStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

int main()
{
    stack<int> Divyam;
    Divyam.push(3);
    Divyam.push(5);
    Divyam.push(7);

    cout << "The Stack is : " << endl;
    PrintStack(Divyam);

    // cout<<"The Reversed Stack is : "<<endl;
    // stack<int> ans = ReverseStack1(Divyam);
    // PrintStack(ans);

    cout << "The Reversed Stack is : " << endl;
    ReverseStack2(Divyam);
    PrintStack(Divyam);
    return 0;
}