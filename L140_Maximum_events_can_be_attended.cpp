#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solve(vector<vector<int>> events)
{
    vector<pair<int, int>> vis;
    for (int i = 0; i < events.size(); i++)
    {
        pair<int, int> p = make_pair(events[i][0], events[i][1]);
        vis.push_back(p);
    }
    sort(vis.begin(), vis.end(), cmp);

    int cnt = 1;
    int ansEnd = vis[0].second;

    for (int i = 0; i < events.size(); i++)
    {
        if (vis[i].first > vis[0].second)
        {
            cnt++;
            ansEnd = vis[i].second;
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> events = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    cout << solve(events) << endl;
    return 0;
}
