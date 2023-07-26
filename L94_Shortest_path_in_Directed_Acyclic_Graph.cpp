#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjlist;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adjlist[u].push_back(p);
    }

    void PrintAdjList()
    {
        for (auto i : adjlist)
        {
            cout << i.first << "->";
            for (auto j : i.second)
                cout << "[" << j.first << ", " << j.second << "] ,";
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[node] = true;

        for (auto neighbour : adjlist[node])
        {
            if (!visited[neighbour.first])
                dfs(neighbour.first, visited, topo);
        }
        topo.push(node);
    }

    void ShortestPath(int src_node, vector<int> &dist, stack<int> &s)
    {
        dist[src_node] = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if (dist[top] != INT16_MAX)
            {
                for (auto i : adjlist[top])
                {
                    if (dist[top] + i.second < dist[i.first])
                        dist[i.first] = dist[top] + i.second;
                }
            }
        }
    }
};

int main()
{

    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.PrintAdjList();

    // Topological sort
    stack<int> s;
    unordered_map<int, bool> visited;
    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
            g.dfs(i, visited, s);
    }

    int src_node = 1;
    vector<int> dist;

    for (int i = 0; i < 6; i++)
        dist[i] = INT16_MAX;

    g.ShortestPath(src_node, dist, s);

    cout << "The vector consisting from shortest paths is " << endl;

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INT16_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}