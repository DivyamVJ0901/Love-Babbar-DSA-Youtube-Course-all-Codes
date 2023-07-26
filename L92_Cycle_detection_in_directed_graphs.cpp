#include <bits/stdc++.h>
using namespace std;

void AdjListFormation(unordered_map<int, list<int>> &adjlist, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
    }
}

bool isCyclePresent(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adjlist)
{
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbour : adjlist[node])
    {
        if (!visited[neighbour])
        {
            // visited not true
            if (isCyclePresent(neighbour, visited, dfsvisited, adjlist))
                return true;
        }
        else if (dfsvisited[neighbour])
        {
            // visited true
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    unordered_map<int, list<int>> adjlist;
    AdjListFormation(adjlist, edges);
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (isCyclePresent(i, visited, dfsvisited, adjlist))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<pair<int, int>> ques = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    bool ans = detectCycleInDirectedGraph(5, ques);
    if (ans)
        cout << "YES YES " << endl;
    else
        cout << "NO NO " << endl;
    return 0;
}