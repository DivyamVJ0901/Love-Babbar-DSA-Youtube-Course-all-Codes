#include <bits/stdc++.h>
using namespace std;

int solveByRecursion(int index, bool buy, vector<int> &prices, int limit)
{
    if (index == prices.size() || limit == 0)
        return 0;
    int profit = 0;
    if (buy)
        profit = max((-prices[index] + solveByRecursion(index + 1, 0, prices, limit)), (solveByRecursion(index + 1, 1, prices, limit)));
    else
        profit = max((prices[index] + solveByRecursion(index + 1, 1, prices, limit - 1)), (solveByRecursion(index + 1, 0, prices, limit)));

    return profit;
}

int solveByMemoization(int index, bool buy, vector<int> &prices, vector<vector<vector<int>>> &dp, int limit)
{
    if (index == prices.size() || limit == 0)
        return 0;

    if (dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

    int profit = 0;
    if (buy)
        profit = max((-prices[index] + solveByMemoization(index + 1, 0, prices, dp, limit)), (solveByMemoization(index + 1, 1, prices, dp, limit)));
    else
        profit = max((prices[index] + solveByMemoization(index + 1, 1, prices, dp, limit - 1)), (solveByMemoization(index + 1, 0, prices, dp, limit)));

    dp[index][buy][limit] = profit;
    return dp[index][buy][limit];
}

int solveByTabulation(vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int index = prices.size() - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy)
                    profit = max((-prices[index] + dp[index + 1][0][limit]), dp[index + 1][1][limit]);
                else
                    profit = max((prices[index] + dp[index + 1][1][limit - 1]), dp[index + 1][0][limit]);
                dp[index][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int solveBySO(vector<int> &prices)
{
    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));
    for (int index = prices.size() - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy)
                    profit = max((-prices[index] + next[0][limit]), next[1][limit]);
                else
                    profit = max((prices[index] + next[1][limit - 1]), next[0][limit]);
                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }
    return next[1][2];
}

int maxProfit(vector<int> &prices)
{
    // return solveByRecursion(0 , 1 , prices , 2);

    // vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2 , vector<int>(3 , -1)));
    // return solveByMemoization(0 , 1 , prices , dp , 2);

    // return solveByTabulation(prices);

    return solveBySO(prices);
}

int main()
{
    vector<int> ques = {3,3,5,0,0,3,1,4};
    cout<<maxProfit(ques);
    return 0;
}