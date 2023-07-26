#include <bits/stdc++.h>
using namespace std;

// USING RECURSION
int solve(vector<int> &satisfaction, int index, int time)
{
    if (index >= satisfaction.size())
        return 0;

    int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1);
    int exclude = solve(satisfaction, index + 1, time);

    return max(include, exclude);
}

// USING TOP DOWN APPROACH
int solveByMemoization(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
{
    if (index >= satisfaction.size())
        return 0;

    if (dp[index][time] != -1)
        return dp[index][time];

    int include = satisfaction[index] * (time + 1) + solveByMemoization(satisfaction, index + 1, time + 1, dp);
    int exclude = solveByMemoization(satisfaction, index + 1, time, dp);

    dp[index][time] = max(include, exclude);
    return dp[index][time];
}

int maxSatisfaction(vector<int> &satisfaction)
{
    // using Recursion
    // return solve(satisfaction, 0, 0);

    // using Memoization
    int n = satisfaction.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveByMemoization(satisfaction, 0, 0, dp);
}

int main()
{
    vector<int> ques = {-1, -8, 0, 5, -9};
    cout << maxSatisfaction(ques);
    return 0;
}