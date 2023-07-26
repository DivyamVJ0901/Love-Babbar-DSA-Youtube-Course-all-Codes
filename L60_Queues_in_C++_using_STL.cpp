// Implementation of QUEUE in C++ using STL
#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> que;
    que.push(1);
    que.push(5);
    que.push(4);
    que.push(12);
    que.push(8);
    cout << que.front() << endl;
    cout << que.back() << endl;
    cout<<"Size of Queue is : "<<que.size()<<endl;
    que.pop();
    que.pop();
    que.pop();
    que.pop();
    que.pop();
    cout<<"Size of Queue is : "<<que.size()<<endl;
    
    if(que.empty())
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Queue is non-empty"<<endl;
    return 0;
}