#include <bits/stdc++.h>
using namespace std;

void AdjListFormation(unordered_map<int, list<int>> &adjlist, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
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
            // viisted not true
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

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
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
                return 1;
        }
    }
    return 0;
}

int main()
{
    vector<pair<int, int>> ques = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
    if (detectCycleInDirectedGraph(5, ques) == 0)
        cout << "Cycle is absent" << endl;
    else
        cout << "Cycle is present" << endl;
    return 0;
}