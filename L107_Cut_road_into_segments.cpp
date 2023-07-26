#include <bits/stdc++.h>
using namespace std;

// SOLVE BY RECURSION
int solveByRecursion(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    int firstSegment = solveByRecursion(n - x, x, y, z) + 1;
    int secondSegment = solveByRecursion(n - y, x, y, z) + 1;
    int thirdSegment = solveByRecursion(n - z, x, y, z) + 1;

    int ans = max(firstSegment, max(secondSegment, thirdSegment));

    return ans;
}

// SOLVE BY MEMOIZATION
int solveByMemoization(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    if (dp[n] != -1)
        return dp[n];

    int firstSegment = solveByMemoization(n - x, x, y, z, dp) + 1;
    int secondSegment = solveByMemoization(n - y, x, y, z, dp) + 1;
    int thirdSegment = solveByMemoization(n - z, x, y, z, dp) + 1;

    dp[n] = max(firstSegment, max(secondSegment, thirdSegment));

    return dp[n];
}

// SOLVE BY TABULATION
int solveByTabulation(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0 && dp[i - x] != -1)
            dp[i] = max(dp[i], dp[i - x] + 1);

        if (i - y >= 0 && dp[i - y] != -1)
            dp[i] = max(dp[i], dp[i - y] + 1);

        if (i - z >= 0 && dp[i - z] != -1)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    if (dp[n] < 0)
        return 0;
    return dp[n];
}

// NO SPACE OPTIMISATION POSSIBLE FOR THIS

int segments(int n, int x, int y, int z)
{
    // return solveByRecursion(n, x, y, z);

    vector<int> dp(n + 1, -1);
    // return solveByMemoization(n, x, y, z, dp);

    return solveByTabulation(n, x, y, z);

}

int main()
{
    int a = 7, b = 5, c = 2, d = 2;
    cout << segments(a, b, c, d) << endl;
    return 0;
}