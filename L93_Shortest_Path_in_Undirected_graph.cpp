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

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int s, int t)
{
    unordered_map<int, list<int>> adjlist;
    AdjListFormation(adjlist, edges);
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    // BFS call kr diya
    queue<int> que;
    que.push(s);
    parent[s] = -1;
    visited[s] = true;
    while (!que.empty())
    {
        int front = que.front();
        que.pop();

        for (auto neighbour : adjlist[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = front;
                que.push(neighbour);
            }
        }
    }

    // vector me sabke intial node se target node tk jaane ke paths ko install kr diya
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while (currNode != s)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void Print(vector<int> arr)
{
    cout<<"{";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ",";
    cout << "}" << endl;
}

int main()
{
    vector<pair<int, int>> ques = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 8}, {4, 6}, {5, 8}, {6, 7}, {7, 8}};
    vector<int> ans = shortestPath(ques, 4, 1, 8);
    Print(ans);
    return 0;
}