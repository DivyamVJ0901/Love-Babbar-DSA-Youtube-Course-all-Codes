#include <iostream>
#include <stack>
using namespace std;

// ITERATIVE APPROACH
stack<int> pushAtBottom1(stack<int> &myStack, int x)
{
    stack<int> temp;
    int num = myStack.top();

    while (!myStack.empty())
    {
        temp.push(myStack.top());
        myStack.pop();
    }
    myStack.push(x);
    while (!temp.empty())
    {
        myStack.push(temp.top());
        temp.pop();
    }
    return myStack;
}

// RECURSIVE APPROACH
void pushAtBottom2(stack<int> &stack, int x)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }

    int num = stack.top();
    stack.pop();

    pushAtBottom2(stack, x);
    stack.push(num);
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
    Divyam.push(7);
    Divyam.push(1);
    Divyam.push(4);
    Divyam.push(5);
    cout<<"The given Stack is :"<<endl; 
    PrintStack(Divyam);

    // stack<int> Vijay = pushAtBottom1(Divyam, 9);
    // cout<<"The updated Stack is :"<<endl; 
    // PrintStack(Vijay);

    cout<<"The updated Stack is :"<<endl;
    pushAtBottom2(Divyam , 9);
    PrintStack(Divyam); 
    return 0;
}