#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007;

int solveByRec(int dice, int faces, int target)
{
    if ((target < 0) || (dice != 0 && target == 0) || (dice == 0 && target != 0))
        return 0;
    if (dice == 0 || target == 0)
        return 1;
    int ans = 0;
    for (int i = 1; i <= faces; i++)
        ans += solveByRec(dice - 1, faces, target - i);
    return ans;
}

int solveByMemoization(int dice, int faces, int target, vector<vector<long long>> &dp)
{
    if ((target < 0) || (dice != 0 && target == 0) || (dice == 0 && target != 0))
        return 0;
    if (dice == 0 && target == 0)
        return 1;

    if (dp[dice][target] != -1)
        return dp[dice][target];

    long long ans = 0;
    for (int i = 1; i <= faces; i++)
        ans += solveByMemoization(dice - 1, faces, target - i, dp) % mod;
    dp[dice][target] = ans;

    return dp[dice][target] % mod;
}

int solveByTabulation(int n, int k, int t)
{
    vector<vector<int>> dp(k + 1, vector<int>(t + 1, 0));

    dp[0][0] = 1;

    for (int dice = 1; dice <= n; dice++)
    {
        for (int tar = 1; tar <= t; tar++)
        {
            long long ans = 0;
            for (int i = 1; i <= k; i++)
            {
                if (tar - i >= 0)
                    ans += dp[dice - 1][tar - i] % mod;
            }
            dp[dice][tar] = ans % mod;
        }
    }
    return dp[n][t];
}

int solveBySO(int n, int k, int t)
{
    vector<int> curr(t + 1, 0);
    vector<int> prev(t + 1, 0);
    
    prev[0] = 1; // After analysis of base case

    for (int dice = 1; dice <= n; dice++)
    {
        for (int tar = 1; tar <= t; tar++)
        {
            long long ans = 0;
            for (int i = 1; i <= k; i++)
            {
                if (tar - i >= 0)
                    ans += prev[tar - i] % mod;
            }
            curr[tar] = ans % mod;
        }
        prev = curr;
    }
    return prev[t];
}

int numRollsToTarget(int n, int k, int target)
{
    // return solveByRec(n , k , target);

    // vector<vector<long long>> dp(k + 1, vector<long long>(target + 1, -1));
    // return solveByMemoization(n, k, target, dp);

    // return solveByTabulation(n, k, target);

    return solveBySO(n , k , target);
}

int main()
{
    int n = 30, k = 30, target = 500;
    cout << numRollsToTarget(n, k, target);
    return 0;
}