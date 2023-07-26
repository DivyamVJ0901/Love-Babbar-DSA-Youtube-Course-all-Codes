#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int &timer, vector<int> &disc, vector<int> &low, int parent, unordered_map<int, bool> &visited, vector<int> &ap_pts, unordered_map<int, list<int>> &adjlist)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;

    int child = 0;
    for (auto neighbour : adjlist[node])
    {
        if (neighbour == parent)
            continue;
        if (!visited[neighbour])
        {
            dfs(neighbour, timer, disc, low, node, visited, ap_pts, adjlist);
            low[node] = min(low[node], low[neighbour]);
            // Check AP or not  
            if (low[neighbour] >= disc[node] && parent != -1)
                ap_pts[node] = true;
            child++;
        }
        else
            // node already visited and node is not a parent ,, that means it is a backedge
            low[node] = min(low[node], disc[neighbour]);
    }
    if (parent == -1 && child > 1)
        ap_pts[node] = true;
}

int main()
{
    int v = 5;
    int e = 5 ;
    vector<pair<int, int>> ques = {{0, 3}, {3, 4}, {0, 4}, {0, 1}, {1, 2}};
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < e; i++)
    {
        int u = ques[i].first;
        int v = ques [i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    unordered_map<int, bool> visited;

    vector<int> ap_pts(v,0);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(i, timer, disc, low, parent, visited, ap_pts, adjlist);
    }

    cout << "Articulation points are : " << endl;
    for (int i = 0; i < v; i++)
    {
        if(ap_pts[i] != 0)
            cout<<i<<" ";
    }
    
    return 0;
}