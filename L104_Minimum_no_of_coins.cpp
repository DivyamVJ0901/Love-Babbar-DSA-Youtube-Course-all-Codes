#include <bits/stdc++.h>
using namespace std;

int solveByRecursion(vector<int> &num, int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    int mini = INT_MAX;

    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveByRecursion(num, x - num[i]);

        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    return mini;
}
int solveByMemoization(vector<int> &num, int x, vector<int> &dp)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
        return dp[x];

    int mini = min(mini, INT_MAX);

    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveByMemoization(num, x - num[i] , dp);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    dp[x] = mini;
    return dp[x];
}
int solveByTabulation(vector<int> &num, int x, vector<int> &dp)
{
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {       
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
        }
    }
    if(dp[x] == INT_MAX)
        return -1;
    return dp[x];
}

// NO SPACE OPTIMISATION IS NOT POSSIBLE
int minimumElements(vector<int> &num, int x)
{
    // RECURSION
    // int ans = solveByRecursion(num, x);
    // if (ans == INT_MAX)
    //     return -1;
    // return ans;

    // MEMOIZATION
    // vector<int> dp(x + 1, -1);
    // return solveByMemoization(num, x, dp);

    // TABULATION
    // vector<int> dp(x + 1, INT_MAX);
    // return solveByTabulation(num, x, dp);
     
}

int main()
{
    vector<int> ques = {1, 2, 5};
    cout << minimumElements(ques, 11);
    return 0;
}