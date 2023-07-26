#include <bits/stdc++.h>
using namespace std;

queue<int> revereseFirstK(queue<int> q, int k)
{
    stack<int> s;
    queue<int> temp;

    queue<int> que = q;
    for (int i = 0; i < k; i++)
    {
        s.push(que.front());
        que.pop();
    }
    while (!que.empty())
    {
        temp.push(que.front());
        que.pop();
    }

    while (!s.empty())
    {
        que.push(s.top());
        s.pop();
    }

    while (!temp.empty())
    {
        que.push(temp.front());
        temp.pop();
    }
    return que;
}

int main()
{
    queue<int> cheems;
    cheems.push(1);
    cheems.push(2);
    cheems.push(3);
    cheems.push(4);
    cheems.push(5);
    queue<int> ans = revereseFirstK(cheems, 3);
    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }
    return 0;
}