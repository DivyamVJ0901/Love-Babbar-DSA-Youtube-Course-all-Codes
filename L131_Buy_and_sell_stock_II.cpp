#include <bits/stdc++.h>
using namespace std;

// SOLVE BY RECURSION
int solveByRecursion(int index, bool buy, vector<int> &prices)
{
    if (index == prices.size())
        return 0;

    int profit = 0;
    if (buy)
        profit = max((-prices[index] + solveByRecursion(index + 1, 1, prices)), (solveByRecursion(index + 1, 0, prices)));
    else
        profit = max((prices[index] + solveByRecursion(index + 1, 1, prices)), (solveByRecursion(index + 1, 0, prices)));
    return profit;
}

// SOLVE BY MEMOIZATION
int solveByMemoization(int index, bool buy, vector<int> &prices, vector<vector<int>> &dp)
{
    if (index == prices.size())
        return 0;
    
    if(dp[index][buy] != -1)
    return dp[index][buy];

    int profit = 0;
    if (buy)
        profit = max((-prices[index] + solveByMemoization(index + 1, 1, prices, dp)), (solveByMemoization(index + 1, 0, prices, dp)));
    else
        profit = max((prices[index] + solveByMemoization(index + 1, 1, prices, dp)), (solveByMemoization(index + 1, 0, prices, dp)));
    dp[index][buy] = profit;
    return dp[index][buy];
}

// SOLVE BY TABULATION
int solveByTabulation(vector<int> &prices)
{
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
    for (int index = prices.size() - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max((-prices[index] + dp[index + 1][0]), dp[index + 1][1]);
            else
                profit = max((prices[index] + dp[index + 1][1]), dp[index + 1][0]);
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

// SOLVE BY SPACE OPTIMISATION
int solveBySO(vector<int> &prices)
{
    vector<int> curr(2, 0);
    vector<int> next(2, 0);
    for (int index = prices.size() - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max((-prices[index] + next[0]), next[1]);
            else
                profit = max((prices[index] + next[1]), next[0]);
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}
int maxProfit(vector<int> &prices)
{
    // Using recursion
    // return solveByRecursion(0 , 1, prices);

    // Using memoization
    // int s = prices.size();
    // vector<vector<int>> dp(s + 1, vector<int>(2, -1));
    // return solveByMemoization(0, 1, prices, dp);

    // Using tabulation
    // return solveByTabulation(prices);

    // Using Space Optimisation
    return solveBySO(prices);
}

int main()
{
    vector<int> ques = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(ques);
    return 0;
}