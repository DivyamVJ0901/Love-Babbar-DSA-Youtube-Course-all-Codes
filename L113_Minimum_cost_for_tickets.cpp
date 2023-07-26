#include <bits/stdc++.h>
using namespace std;

// USING RECURSION
int solve(int n, vector<int> &days, vector<int> &cost, int index)
{
    // Base case
    if (index >= n)
        return 0;

    // OPTION-1 : 1 DAY PASS
    int option1 = cost[0] + solve(n, days, cost, index + 1);

    int i;
    // OPTION-2 : 7 DAYS PASS
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int option2 = cost[1] + solve(n, days, cost, i);

    // OPTION-3 : 30 DAYS PASS
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option2, option3));
}

// USING MEMOIZATION
int solveByMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int option1 = cost[0] + solve(n, days, cost, index + 1);

    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int option2 = cost[1] + solve(n, days, cost, i);

    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int option3 = cost[2] + solve(n, days, cost, i);

    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

// USING TABULATION
int solveByTab(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        int option1 = cost[0] + dp[k + 1];

        int i;
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;
        int option2 = cost[1] + dp[i];

        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}

int minCost(int n, vector<int> days, vector<int> cost)
{
    // Using Recursion
    // return solve(n, days, cost, 0);

    // Using Memoization
    // vector<int> dp(n + 1, -1);
    // return solveByMem(n, days, cost, 0, dp);

    return solveByTab(n, days, cost);
}

int main()
{
    int n = 2;
    vector<int> days = {2, 5};
    vector<int> cost = {1, 4, 25};
    cout << minCost(n, days, cost);
    return 0;
}