#include <bits/stdc++.h>
using namespace std;

int solveByRecursion(int index, int buy, vector<int> &prices, int limit)
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

int solveByTabulation(vector<int> &prices, int k)
{
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 2, 0)));
    for (int index = prices.size() - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= k; limit++)
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
    return dp[0][1][k];
}

int solveBySpaceOptimisation(vector<int> &prices, int k)
{
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));
    vector<vector<int>> next(2, vector<int>(k + 1, 0));
    for (int index = prices.size() - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= k; limit++)
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
    return next[1][k];
}

int solveByRec(int index, int operation, int k, vector<int> &prices)
{
    if (index == prices.size() || operation == 2 * k)
        return 0;

    int profit = 0;
    if (operation & 1)
        profit = max((prices[index] + solveByRec(index + 1, operation + 1, k, prices)), (solveByRec(index + 1, operation, k, prices)));
    else
        profit = max((-prices[index] + solveByRec(index + 1, operation + 1, k, prices)), (solveByRec(index + 1, operation, k, prices)));

    return profit;
}

int solveByMem(int index, int operation, int k, vector<int> prices, vector<vector<int>> &dp)
{
    if (index == prices.size() || operation == 2 * k)
        return 0;

    if (dp[index][operation] != -1)
        return dp[index][operation];

    int profit = 0;
    if (operation & 1)
        profit = max((prices[index] + solveByMem(index + 1, operation + 1, k, prices, dp)), (solveByMem(index + 1, operation, k, prices, dp)));
    else
        profit = max((-prices[index] + solveByMem(index + 1, operation + 1, k, prices, dp)), (solveByMem(index + 1, operation, k, prices, dp)));

    dp[index][operation] = profit;
    return dp[index][operation];
}

int solveByTab(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int operation = 0; operation < 2 * k; operation++)
        {
            int profit = 0;
            if (operation & 1)
                profit = max((prices[index] + dp[index + 1][operation + 1]), (dp[index + 1][operation]));
            else
                profit = max((-prices[index] + dp[index + 1][operation + 1]), (dp[index + 1][operation]));

            dp[index][operation] = profit;
        }
    }
    return dp[0][0];
}

int solveBySO(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<int> curr(2 * k + 1, 0);
    vector<int> next(2 * k + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int operation = 0; operation < 2 * k; operation++)
        {
            int profit = 0;
            if (operation & 1)
                profit = max((prices[index] + next[operation + 1]), (next[operation]));
            else
                profit = max((-prices[index] + next[operation + 1]), (next[operation]));

            curr[operation] = profit;
        }
        next = curr;
    }
    return next[0];
}

int maxProfit(int k, vector<int> &prices)
{
    // return solveByRecursion(0 , 1 , prices , k);

    // int s = prices.size();
    // vector<vector<vector<int>>> dp(s + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    // return solveByMemoization(0 , 1 , prices , dp , k);

    // return solveByTabulation(prices , k);

    // return solveBySpaceOptimisation(prices, k);

    // return solveByRec(0 , 0 , k , prices);

    // vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k, -1));
    // return solveByMem(0, 0, k, prices, dp);

    // return solveByTab(k , prices);

    return solveBySO(k, prices);
}

int main()
{
    vector<int> ques = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << maxProfit(k, ques);
    return 0;
}