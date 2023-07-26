#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// template ka use krke bhi hum kar skte hai ,, jaha jaha int hai vaha T daal dena
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool Direction)
    {
        // If the graph is Undirected , then direction == 0
        // If the graph is Directed , then direction == 1
        adj[u].push_back(v);
        if (Direction == 0)
            adj[v].push_back(u);
    }

    void PrintAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
                cout << j << ", ";
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter the number of nodes : " << endl;
    cin >> n;

    cout << "Enter the number of edges : " << endl;
    cin >> m;

    Graph<int> g;
    cout << "Enter the connections : " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // Undirected graph
    }
    g.PrintAdjList();
    return 0;
}
