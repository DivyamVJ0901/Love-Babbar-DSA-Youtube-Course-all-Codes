#include <bits/stdc++.h>
using namespace std;

void AdjListFormation(unordered_map<int, list<int>> &adjlist, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

void dfsTraversal(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjlist, vector<int> &component)
{
    component.push_back(node);

    for (auto i : adjlist[node])
    {
        if (!visited[i])
            dfsTraversal(i, visited, adjlist, component);
    }
}

vector<vector<int>> DFS(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    unordered_map<int, list<int>> adjlist;
    AdjListFormation(adjlist, edges);
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            vector<int> component;
            dfsTraversal(i, visited, adjlist, component);
            ans.push_back(component);
        }
    }
    return ans;
}

void Print(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
            cout << arr[i][j] << " "; 
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> ques = {{0, 2}, {0, 1}, {1, 2}, {3, 4}};
    int V = 5, E = 4;
    vector<vector<int>> ans = DFS(V, E, ques);
    Print(ans);
    return 0;
}