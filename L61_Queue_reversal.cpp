#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> que)
{
    stack<int> s;

    while (!que.empty())
    {
        s.push(que.front());
        que.pop();
    }

    while (!s.empty())
    {
        que.push(s.top());
        s.pop();
    }

    return que;
}

int main()
{
    queue<int> ques;
    ques.push(6);
    ques.push(5);
    ques.push(4);
    ques.push(3);
    ques.push(2);
    ques.push(1);

    while (!ques.empty())
    {
        cout << ques.front() << " ";
        ques.pop();
    }

    queue<int> ans = reverseQueue(ques);

    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    return 0;
}