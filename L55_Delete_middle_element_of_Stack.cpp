#include <iostream>
#include <stack>
using namespace std;

// We are solving this question using RECURSION

void Solve(stack<int>&inputStack, int count, int size)
{
    // Base case
    if (count == (size / 2))
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top(); 
    inputStack.pop();    

    // Recursive call
    Solve(inputStack , count + 1 , size);
    inputStack.push(num);
}   

int main()
{
    stack<int> cheems;
    cheems.push(10);
    cout<<cheems.top()<<endl;
    cheems.push(20);
    cout<<cheems.top()<<endl;
    cheems.push(30);
    cout<<cheems.top()<<endl;
    cheems.push(40);
    cout<<cheems.top()<<endl;
    cheems.push(50);
    cout<<cheems.top()<<endl;
    int count = 0;
    Solve(cheems , count , cheems.size());
    cout<<endl;
    cout<<cheems.top()<<endl;
    cheems.pop();
    cout<<cheems.top()<<endl;
    cheems.pop();
    cout<<cheems.top()<<endl;
    cheems.pop();
    cout<<cheems.top()<<endl;
    cheems.pop();
    cout<<cheems.top()<<endl;
    return 0;   
}