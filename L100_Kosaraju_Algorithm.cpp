#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adjlist)
{
    visited[node] = true;

    for (auto neighbour : adjlist[node])
    {
        if (!visited[neighbour])
            dfs(neighbour, visited, st, adjlist);
    }
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjlist)
{
    visited[node] = true;

    for (auto neighbour : adjlist[node])
    {
        if (!visited[neighbour])
            revDfs(neighbour, visited, adjlist);
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    int cnt = 0;
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < edges.size(); i++)
    {
        adjlist[edges[i][0]].push_back(edges[i][1]);
    }

    // topo sort
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(i, visited, st, adjlist);
    }

    // Create a transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        for (auto neighbour : adjlist[i])
            transpose[neighbour].push_back(i);
    }

    for (int i = 0; i < v; i++)
        visited[i] = 0; // Kyuki ye update hogya uper se , neeche hum dobara DFS call kr rahe hai to jrurat padegi

    // dfs call using topo sort
    while (!st.empty())
    {
        int front = st.top();
        st.pop();

        if (!visited[front])
        {
            cnt++;
            revDfs(front, visited, transpose);
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> ques = {{2, 0}, {1, 2}, {0, 1}, {1, 3}, {3, 4}};
    cout << stronglyConnectedComponents(5, ques) << endl;
    return 0;
}