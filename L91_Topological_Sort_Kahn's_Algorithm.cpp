#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<pair<int, int>> &edges, int N, int M)
{
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
    }
    //     Indegree store krali
    vector<int> indegree(N);
    for (auto i : adjlist)
    {
        for (auto j : i.second)
            indegree[j]++;
    }

    //     0 indegree walo ko push kr diya
    queue<int> que;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            que.push(i);
    }

    vector<int> ans;
    while (!que.empty())
    {
        int front = que.front();
        que.pop();

        ans.push_back(front);

        for (auto neighbour : adjlist[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                que.push(neighbour);
        }
    }
    return ans;
}

void Print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
    vector<pair<int, int>> ques = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {1, 4}};
    vector<int> ans = topologicalSort(ques ,4,5);
    Print(ans);
    return 0;
}