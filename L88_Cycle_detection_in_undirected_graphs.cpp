#include <bits/stdc++.h>
using namespace std;

void AdjListFormation(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjlist)
{
    for (int i = 0; i < edges[0].size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

bool isCyclePresentUsingBFS(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjlist)
{
    unordered_map<int, int> parent;

    parent[node] = -1;
    visited[node] = true;

    queue<int> que;
    que.push(node);

    while (!que.empty())
    {
        int front = que.front();
        que.pop();

        for (auto neighbour : adjlist[front])
        {
            if (visited[neighbour] == true && neighbour != parent[front])
                return true;
            else if (!visited[neighbour])
            {
                que.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

bool isCyclePresentUsingDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjlist)
{
    visited[node] = true;
    for (auto neighbour : adjlist[node])
    {
        if (!visited[neighbour])
        {
            if (isCyclePresentUsingDFS(neighbour, node, visited, adjlist))  
                return true;
        }   
        else if (neighbour != parent)
            return true;
    }
    return false;
}

string cycleDetectionUsingBFS(vector<vector<int>> &edges, int n, int m)
{
        unordered_map<int, list<int>> adjlist;
        AdjListFormation(edges, adjlist);
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                bool ans = isCyclePresentUsingBFS(i, visited, adjlist);
                if (ans == 1)
                    return "YES";
            }
        }
        return "NO";
}

string cycleDetectionUsingDFS(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adjlist;
    AdjListFormation(edges, adjlist);
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclePresentUsingDFS(i, -1,visited, adjlist);
            if (ans == 1)
                return "YES";
        }
    }
    return "NO";    
}

int main()
{
    vector<vector<int>> edges = {{3, 2}, {1, 2}, {2, 3}};
    cout << cycleDetectionUsingBFS(edges, 3, 3) << endl;
    cout << cycleDetectionUsingDFS(edges , 3, 3) << endl;
    return 0;
}