#include <bits/stdc++.h>
using namespace std;

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> distance(n + 1, 1e9);
    distance[src] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (distance[u] != 1e9 && ((distance[u] + w < distance[v])))
                distance[v] = distance[u] + w;
        }
    }
    return distance[dest];

    // CHECK FOR NEGATIVE CYCLES
    // bool flag = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         int u = edges[j][0];
    //         int v = edges[j][1];
    //         int w = edges[j][2];

    //         if (distance[u] != 1e9 && ((distance[u] + w < distance[v])))
    //             flag = true;
    //     }
    // }

    // if (flag == 0)
    //     return distance[dest];

    // return -1;
}

int main()
{
    vector<vector<int>> ques = {{1, 2, 4}, {1, 3, 3}, {2, 4, 7}, {3, 4, -2}};
    int ans = bellmanFord(4, 4, 1, 4, ques);
    cout << ans << endl;
    return 0;
}