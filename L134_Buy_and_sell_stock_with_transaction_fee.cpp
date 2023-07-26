#include <bits/stdc++.h>
using namespace std;

int solveByRec(int index, bool buy, vector<int> &prices, int fee)
{
    if (index == prices.size())
        return 0;
    int profit = 0;
    if (buy)
        profit = max((-prices[index] + solveByRec(index + 1, 0, prices, fee)), (solveByRec(index + 1, 1, prices, fee)));
    else
        profit = max((prices[index] + solveByRec(index + 1, 1, prices, fee) - fee), (solveByRec(index + 1, 0, prices, fee)));
    return profit;
}

int solveByMemoization(int index, bool buy, vector<int> &prices, int fee, vector<vector<int>> &dp)
{
    if (index == prices.size())
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;
    if (buy)
        profit = max((-prices[index] + solveByMemoization(index + 1, 0, prices, fee, dp)), (solveByMemoization(index + 1, 1, prices, fee, dp)));
    else
        profit = max((prices[index] + solveByMemoization(index + 1, 1, prices, fee, dp) - fee), (solveByMemoization(index + 1, 0, prices, fee, dp)));

    dp[index][buy] = profit;
    return dp[index][buy];
}

int solveByTabulation(vector<int> &prices, int fee)
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
                profit = max((prices[index] + dp[index + 1][1] - fee), dp[index + 1][0]);
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

int solveBySpaceOptimisation(vector<int> &prices, int fee)
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
                profit = max((prices[index] + next[1] - fee), next[0]);
            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}

int maxProfit(vector<int> &prices, int fee)
{
    //  return solveByRec(0 , 1 , prices , fee);
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    // return solveByMemoization(0 , 1 , prices , fee , dp);

    // return solveByTabulation(prices , fee);

    return solveBySpaceOptimisation(prices, fee);
}

int main()
{
    vector<int> ques = {1,3,2,8,4,9};
    int fees = 2;
    cout<<maxProfit(ques , fees);
    return 0;
}