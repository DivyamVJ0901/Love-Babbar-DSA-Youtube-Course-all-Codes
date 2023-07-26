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

void bfsTraversal(unordered_map<int, list<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> que;
    que.push(node);

    visited[node] = 1;

    while (!que.empty())
    {
        int frontNode = que.front();
        que.pop();

        ans.push_back(frontNode);
        for (auto i : adjlist[frontNode])
        {
            if (!visited[i])
            {
                que.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, bool> visited;

    AdjListFormation(adjlist, edges);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfsTraversal(adjlist, visited, ans, i);
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
    vector<pair<int, int>> ques = {{0, 1}, {1, 2}, {2, 1}, {4, 2}, {4, 3}, {3, 4}, {2, 4}, {2, 3}, {3, 2},{1,0}};
    vector<int> ans = BFS(4, ques);
    cout<<"The BFS traversal of graph is : ";
    Print(ans);
    return 0;
}