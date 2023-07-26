#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int &timer, vector<int> &disc, vector<int> &low, int &parent, unordered_map<int, bool> &visited, vector<vector<int>> &result, unordered_map<int, list<int>> &adjlist)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto neighbour : adjlist[node])
    {
        if (neighbour == parent)
            continue;
        if (!visited[neighbour])
        {
            dfs(neighbour, timer, disc, low, node, visited, result, adjlist);
            low[node] = min(low[node], low[neighbour]);
            // To check bridge is present or not
            if (low[neighbour] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else
            // node already visited and node is not a parent ,, that means it is a backedge 
            low[node] = min(low[node], disc[neighbour]);
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Adj list
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> visited;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }
    

    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(i, timer, disc, low, parent, visited, result, adjlist);
    }
    return result;
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
    vector<vector<int>> ques = {{5, 4}, {0, 1}, {3, 1}, {1, 2}, {3, 4}, {3, 3}, {0, 1}, {1, 2}, {2, 0}};
    vector<vector<int>> ans = findBridges(ques, 6, 7);
    Print(ans);
    return 0;
}