#include <bits/stdc++.h>
using namespace std;

int solveBySpaceOpt(int n, vector<int> &days, vector<int> &cost)
{
    int ans = 0;

    queue<pair<int, int>> Monthly;
    queue<pair<int, int>> Weekly;

    for (int day = 0; day < days.size(); day++)
    {
        while (Monthly.size() > 0 && Monthly.front().first + 30 <= day)
            Monthly.pop();

        while (Weekly.size() > 0 && Weekly.front().first + 7 <= day)
            Weekly.pop();

        Monthly.push(make_pair(day, ans + cost[2]));

        Weekly.push(make_pair(day, ans + cost[1]));

        ans = min(ans + cost[0], min(Monthly.front().second, Weekly.front().second));
    }

    return ans;
}

int minCost(int n, vector<int> days, vector<int> cost)
{
    // Using Recursion
    // return solve(n, days, cost, 0);

    // Using Memoization
    // vector<int> dp(n + 1, -1);
    // return solveByMem(n, days, cost, 0, dp);

    return solveBySpaceOpt(n, days, cost);
}

int main()
{
    int n = 2;
    vector<int> days = {2, 5};
    vector<int> cost = {1, 4, 25};
    cout << minCost(n, days, cost);
    return 0;
}