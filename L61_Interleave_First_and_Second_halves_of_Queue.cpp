#include <bits/stdc++.h>
using namespace std;

queue<int> firstAndSecondHalvesUsingQueue(queue<int> que)
{
    queue<int> temp_que;
    int cnt = 0;
    int k = que.size() / 2;
    while (!que.empty())
    {
        temp_que.push(que.front());
        que.pop();
        cnt++;
        if (cnt == k)
            break;
    }

    while (!temp_que.empty())
    {
        que.push(temp_que.front());
        temp_que.pop();

        que.push(que.front());
        que.pop();
    }
    return que;
}

queue<int> firstAndSecondHalvesUsingStack(queue<int> q)
{
    stack<int> s;
    int cnt = 0;
    int k = q.size() / 2;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
        cnt++;
        if (cnt == k)
            break;
    }
 
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    cnt = 0;
    while (!q.empty())
    {
        q.push(q.front());
        q.pop();
        cnt++;
        if (cnt == k)
            break;
    }

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
        cnt++;
        if (cnt == k)
            break;
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{
    queue<int> ques;
    ques.push(11);
    ques.push(12);
    ques.push(13);
    ques.push(14);
    ques.push(15);
    ques.push(16);
    ques.push(17);
    ques.push(18);

    queue<int> ans = firstAndSecondHalvesUsingQueue(ques);
    queue<int> ans2 = firstAndSecondHalvesUsingStack(ques);

    cout << "The given queue is : ";
    while (!ques.empty())
    {
        // cout << ques.front() << " ";
        ques.pop();
    }

    cout << endl;

    cout << "The resultant queue (using queue) is : ";
    while (!ans.empty())
    {
        // cout << ans.front() << " ";
        ans.pop();
    }

    cout << endl;

    cout << "The resultant queue (using stack) is : ";
    while (!ans2.empty())
    {
        cout << ans2.front() << " ";
        ans2.pop();
    }

    return 0;
}
