#include <bits/stdc++.h>
using namespace std;

// USING RECURSION
int solveByRec(vector<int> &values, int s, int e)
{
    s = 0;
    e = values.size() - 1;

    if ((s + 1) == e)
        return 0;

    int ans = INT_MAX;
    for (int k = s + 1; k < e; k++)
    {
        ans = min(solveByRec(values, s, k) + solveByRec(values, k, e) + values[s] * values[e] * values[k], ans);
    }
    return ans;
}

// USING MEMOIZATION
int solveByMem(vector<int> &values, int s, int e, vector<vector<int>> &dp)
{
    if ((s + 1) == e)
        return 0;

    if (dp[s][e] != -1)
        return dp[s][e];

    int ans = INT_MAX;
    for (int k = s + 1; k < e; k++)
    {
        ans = min(solveByMem(values, s, k, dp) + solveByMem(values, k, e, dp) + values[s] * values[e] * values[k], ans);
    }
    dp[s][e] = ans;
    return dp[s][e];
}

// USING TABULAITON
int solveByTab(vector<int> &values, int s, int e)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) //Bottom up approach hai thats why last se start kr rahe hai 
    {
        for (int j = i + 2; j < n; j++) // 
        {
            int ans = INT_MAX;
            for (int k = s + 1; k < e; k++)
            {
                ans = min(dp[s][k] + dp[k][e] + values[s] * values[e] * values[k], ans);
            }
            dp[s][e] = ans; 
        }
    }
    return dp[0][n - 1];
}

int minScoreTriangulation(vector<int> &values)
{
    // using recursion
    // return solveByRec(values, 0, values.size() - 1);

    // using memoization
    int n = values.size();
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return solveByMem(values, 0, values.size() - 1, dp);

    // using tabulation
    return solveByTab(values, 0, n - 1);
}

int main()
{
    vector<int> ques = {3, 7, 4 , 5};
    cout << minScoreTriangulation(ques);
    return 0;
}