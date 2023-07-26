#include <iostream>
#include <stack>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

// ITERATIVE APPROACH
void SortStack(stack<int> &Vimdhayak_Ji)
{
    vector<int> temp;
    while (!Vimdhayak_Ji.empty())
    {
        temp.push_back(Vimdhayak_Ji.top());
        Vimdhayak_Ji.pop();
    }

    sort(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++)
        Vimdhayak_Ji.push(temp[i]);
}

// RECURSIVE APPROACH
void SortedInsert(stack<int> &dogesh, int &num)
{
    if (dogesh.empty() || dogesh.top() < num)
    {
        dogesh.push(num);
        return;
    }

    int n = dogesh.top();
    dogesh.pop();

    SortedInsert(dogesh, num);
    dogesh.push(n);
}

void SortStackUsingRec(stack<int> &s)
{
    if (s.empty())
        return;

    int num = s.top();
    s.pop();

    SortStackUsingRec(s);
    SortedInsert(s, num);   
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
    stack<int> Vijay;
    Vijay.push(5);
    Vijay.push(-2);
    Vijay.push(9);
    Vijay.push(-7);
    Vijay.push(3);
    cout << "The given stack is : " << endl;
    PrintStack(Vijay);
    SortStack(Vijay);
    cout << "The updated stack is : " << endl;
    PrintStack(Vijay);

    stack<int> Divyam;
    Divyam.push(14);
    Divyam.push(10);
    Divyam.push(06);
    Divyam.push(58);
    Divyam.push(44);
    cout << "The given stack is : " << endl;
    PrintStack(Divyam);
    SortStackUsingRec(Divyam);
    cout << "The updated stack is : " << endl;
    PrintStack(Divyam);
    return 0;
}
