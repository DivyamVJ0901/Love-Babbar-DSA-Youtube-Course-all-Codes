#include <bits/stdc++.h>
using namespace std;

// SIMPLE RECURSION
int solve1(vector<int> &cost, int n)
{
    n = cost.size();
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];

    int ans = cost[n] + min(solve1(cost, n - 1), solve1(cost, n - 2));
    return ans;
}

// TOP DOWN - RECURSION + MEMOIZATION
int solve2(vector<int> &cost, int n, vector<int> &dp)
{
    n = cost.size();
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];

    if (dp[n] != -1)
        return dp[n];

    dp[n] = cost[n] + min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));
    return dp[n];
}

// BOTTOM UP - TABULATION
int solve3(vector<int> &cost, int n)
{
    n = cost.size();
    vector<int> dp(n + 1, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < cost.size(); i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    return min(dp[n - 1], dp[n - 2]);
}

// SPACE OPTIMISATION
int solve4(vector<int> &cost, int n)
{
    n = cost.size();
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < cost.size(); i++)
    {
        int curr = min(prev1, prev2) + cost[i];
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    // FOR SOLVE1
    // int n = cost.size();
    // int ans = min(solve1(cost, n - 1), solve1(cost, n - 2));
    // return ans;

    // FOR SOLVE2
    // int n = cost.size();
    // vector<int> dp(n+1 , -1);
    // int ans = min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));
    // return ans;

    // FOR SOLVE3
    // int n = cost.size();
    // return solve3(cost, n);

    // FOR SOLVE4
    int n = cost.size();
    return solve4(cost, n);
}

int main()
{
    vector<int> ques = {10, 15, 20};
    cout<<"The minimum cost required to reach on top floor : ";
    cout << minCostClimbingStairs(ques);
    return 0;
}