#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int solveByRec(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
{
    // base case : leaf node
    if (left == right)
        return 0;

    int ans = INT_MAX;
    for (int i = left; i < right; i++)
        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solveByRec(arr, maxi, left, i) + solveByRec(arr, maxi, i + 1, right));
    return ans;
}

int solveByMemoization(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right , vector<vector<int>> &dp)
{
    // base case : leaf node
    if (left == right)
        return 0;

    if(dp[left][right] != -1)
        return dp[left][right];

    int ans = INT_MAX;
    for (int i = left; i < right; i++)
        ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solveByMemoization(arr, maxi, left, i ,dp) + solveByMemoization(arr, maxi, i + 1, right ,dp));
    
    dp[left][right] = ans;
    return dp[left][right];
}

int solveByTabulation(vector<int> &arr , map<pair<int, int>, int> &maxi , int left , int right)
{
    vector<vector<int>> dp(arr.size() + 1 , vector<int>(arr.size()+1 , 0));

    
}

int mctFromLeafValues(vector<int> &arr)
{
    map<pair<int, int>, int> maxi;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
            maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
    }
    // return solveByRec(arr, maxi, 0, arr.size() - 1);

    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));
    return solveByMemoization(arr, maxi, 0, arr.size() - 1, dp);
}

int main()
{
    vector<int> ques = {3, 6, 4, 7, 2, 5};
    cout << mctFromLeafValues(ques);
    return 0;
}