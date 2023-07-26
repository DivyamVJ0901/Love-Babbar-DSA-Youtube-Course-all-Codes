#include <bits/stdc++.h>
using namespace std;

#define mod 100000007

int add(int a, int b)
{
    return (a % mod + b % mod) % mod;
}

int prod(int a, int b)
{
    return (a % mod * b % mod) % mod;
}

int solve(int n, int k)
{
    if (n == 1)
        return k;

    if (n == 2)
        return add(prod(k, k - 1), k);

    int ans = add(prod(solve(n - 1, k), k - 1), prod(solve(n - 2, k), k - 1));
    return ans;
}

int solveByMemo(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;

    if (n == 2)
        return add(prod(k, k - 1), k);

    if (dp[n] != -1)
        return dp[n];

    dp[n] = add(prod(solve(n - 1, k), k - 1), prod(solve(n - 2, k), k - 1));

    return dp[n];
}

int solveByTab(int n, int k)
{
    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = add(prod(k, k - 1), k);

    for (int i = 3; i <= n; i++)
        dp[i] = add(prod(solve(n - 1, k), k - 1), prod(solve(n - 2, k), k - 1));

    return dp[n];
}

int solveBySpaceOpt(int n, int k)
{
    int prev2 = k;
    int prev1 = add(prod(k, k - 1), k);

    for (int i = 3; i <= n; i++)
    {
        int ans = add(prod(prev2, k - 1), prod(prev1, k - 1));
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int fenceAlgo(int n, int k)
{
    // return solve(n, k);

    // vector<int> dp(n + 1, -1);
    // return solveByMemo(n, k, dp);

    // return solveByTab(n, k);

    return solveBySpaceOpt(n, k);
}

int main()
{
    cout << fenceAlgo(2, 3) << endl;
    cout << fenceAlgo(3, 3) << endl;
    cout << fenceAlgo(4, 3) << endl;
    return 0;
}