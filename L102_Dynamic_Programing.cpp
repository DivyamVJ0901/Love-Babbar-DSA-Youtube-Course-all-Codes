#include <bits/stdc++.h>
using namespace std;

// TOP DOWN : RECURSION + MEMOIZATION
int fib1(int n)
{
    if (n <= 1)
        return n;

    vector<int> dp(n + 1);
    for (int i = 0; i < n + 1; i++)
        dp[i] = -1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib1(n - 1) + fib1(n - 2);
    return dp[n];
}

// BOTTOM UP : TABULATION
int fib2(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// SPACE OPTIMISATION
int fib3(int n)
{
    if (n <= 1)
        return n;

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i < n + 1; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() 
{
    int n;
    cin >> n;
    cout << "The fibonacci number corresponding to position " << n << " is " << fib1(n) << " " << fib2(n) << " " << fib3(n) << endl;
    return 0;
}