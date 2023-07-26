#include <bits/stdc++.h>
using namespace std;

#define mod 100000007

long long int CountDearrangements(int n)
{
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    int ans = (((n - 1) % mod) * ((CountDearrangements(n - 1) % mod) + (CountDearrangements(n - 2) % mod)) % mod);

    return ans;
}

long long int CountDearrangementsByMemoization(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (((n - 1) % mod) * ((CountDearrangements(n - 1) % mod) + (CountDearrangements(n - 2) % mod)) % mod);

    return dp[n];
}

long long int CountDearrangementsByTabulation(int n)
{
    vector<long long int> dp(n + 1, -1);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % mod;
        long long int second = dp[i - 2] % mod;

        long long int ans = ((i - 1) * (first + second)) % mod;

        dp[i] = ans;
    }
    return dp[n];
}

long long int CountDearrangementsBySpaceOptimisation(int n)
{
    long long int prev2 = 0;
    long long int prev1 = 1;
    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1 % mod;
        long long int second = prev2 % mod;

        long long int ans = ((i - 1) * ((first + second) % mod)) % mod;

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int main()
{
    int n = 5;
    vector<long long int> dp(n + 1, -1); 
    cout << CountDearrangements(5) << endl;
    cout << CountDearrangementsByMemoization(5, dp) << endl;
    cout << CountDearrangementsByTabulation(5) << endl;
    cout << CountDearrangementsBySpaceOptimisation(5) << endl;
    return 0;
}