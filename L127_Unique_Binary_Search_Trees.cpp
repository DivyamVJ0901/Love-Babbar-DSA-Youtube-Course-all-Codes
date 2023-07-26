#include <bits/stdc++.h>
using namespace std;

// USING RECURSION
int solve(int n)
{
    if (n <= 1)
        return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += solve(i - 1) * solve(n - i);
    return ans;
}

// USING MEMOIZATION
int solveByMemoization(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];
    
    // i are root nodes
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += solveByMemoization(i - 1, dp) * solveByMemoization(n - i, dp);

    dp[n] = ans;
    return dp[n];
}

// USING TABULATION
int solveByTabulation(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    // i represent number of nodes
    for (int i = 2; i <= n; i++)
    {
        // j represents root node
        for (int j = 1; j <= i; j++)
            dp[i] += dp[j - 1] * dp[i - j];
    }
    return dp[n];
}

int uniqueBST(int n)
{
    // using recursion
    // return solve(n);

    // using memoization
    // vector<int> dp(n + 1, -1);
    // return solveByMemoization(n, dp);

    // using tabulation
    return solveByTabulation(n);
}

int main()
{
    int n = 3;
    cout << uniqueBST(n) << endl;
    return 0;
}
