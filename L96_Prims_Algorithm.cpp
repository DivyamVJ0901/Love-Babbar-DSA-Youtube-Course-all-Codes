#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> PrimsAlgo(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjlist;
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1); // Kyuki mei node ko bhi index se darsha raha hu
    vector<bool> MST(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <=n; i++)
    {
        key[i] = INT_MAX;
        MST[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // Finding the minimum node in key array
        for (int v = 1; v <= n; v++)
        {
            if (MST[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // Marking the node true which is corresponding to the min value in key array
        MST[u] = true;

        for (auto it : adjlist[u])
        {
            int v = it.first;
            int w = it.second;

            // Checking about its adjacent nodes
            if (MST[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
        ans.push_back(make_pair(make_pair(parent[i], i), key[i]));
    return ans;
}

void Print(vector<pair<pair<int, int>, int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].first.first << " " << arr[i].first.second << " " << arr[i].second << endl;
    }
}

int main()
{
    vector<pair<pair<int, int>, int>> ques = {{{1, 2}, 2}, {{1, 4}, 6}, {{2, 1}, 2}, {{2, 3}, 3}, {{2, 4}, 8}, {{2, 5}, 5}, {{3, 2}, 3}, {{3, 5}, 7}, {{4, 1}, 6}, {{4, 2}, 8}, {{4, 5}, 9}, {{5, 2}, 5}, {{5, 3}, 7}, {{5, 4}, 9}};
    vector<pair<pair<int, int>, int>> res = PrimsAlgo(5, 14, ques);
    Print(res);
    return 0;
}