#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int buyAndSellStock(vector<int> &prices)
{
    int mini = prices[0];
    int profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        int diff = prices[i] - mini;
        profit = max(profit, diff);
        mini = min(prices[i], mini);
    }
    return profit;
}

int main()
{
    vector<int> ques = {7, 1, 5, 3, 6, 4};
    cout << buyAndSellStock(ques);
    return 0;
}