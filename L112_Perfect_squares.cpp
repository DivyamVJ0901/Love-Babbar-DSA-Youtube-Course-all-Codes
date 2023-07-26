#include <bits/stdc++.h>
using namespace std;

// USING RECURSION
int solve(int n)
{
    if (n == 0)
        return 0;

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, solve(n - i * i) + 1);
    }

    return ans;
}

// USING MEMOIZATION
int solveByMemo(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, solveByMemo(n - i * i, dp) + 1);
    }
    dp[n] = ans;
    return dp[n];
}

// USING TABULATION
int solveByTab(int n)
{
    vector<int> dp(n+1 , INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1 ; j*j <= n ; j++)
        {
            if(i - j*j >= 0)
                dp[i] = min(dp[i] , dp[i - j*j] + 1);
        }
    }
    return dp[n];
}  

int minSqaures(int n)
{
    vector<int> dp(n + 1, -1);
    // return solve(n);
    // return solveByMemo(n, dp);
    return solveByTab(n);
}

int main()
{
    cout << minSqaures(5);
    return 0;
}