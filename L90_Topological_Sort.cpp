#include <bits/stdc++.h>
using namespace std;

void topSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adjlist)
{
    visited[node] = 1;

    for (auto neighbour : adjlist[node])
    {
        if (!visited[neighbour])
            topSort(neighbour, visited, s, adjlist);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<pair<int, int>> &edges, int N, int M)
{
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
            topSort(i, visited, s, adjlist);
    }

    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
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
    vector<int> ans = topologicalSort(ques, 4, 5);
    Print(ans);
    return 0;
}
