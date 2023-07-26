#include <bits/stdc++.h>
using namespace std;

int solve(int index, int endIndex, vector<int> &slices, int n)
{
    // Base case
    if (n == 0 || index > endIndex)
        return 0;

    int eat = slices[index] + solve(index + 2, endIndex, slices, n - 1); // Jo slice maine khayi uska size add kr diya , and adjacent wali nahi kha skte to index + 2 kiya and slice kha chuka to n-1,
    int notEat = solve(index + 1, endIndex, slices, n);                  // index + 1 hi karenge kyuki maine khayi nahi and khayi nahi to slice kam bhi nahi hui

    return max(eat, notEat);
}

int solveByMemoization(int index, int endIndex, vector<int> &slices, int n, vector<vector<int>> &dp)
{
    if (n == 0 || index > endIndex)
        return 0;

    if (dp[index][n] != -1)
        return dp[index][n];

    int eat = slices[index] + solveByMemoization(index + 2, endIndex, slices, n - 1, dp);
    int notEat = solveByMemoization(index + 1, endIndex, slices, n, dp);

    dp[index][n] = max(eat, notEat);
    return dp[index][n];
}

int solveByTabulation(vector<int> &slices)
{
    int k = slices.size();
    vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
    vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

    for (int index = k - 2; index >= 0; index--)
    {
        for (int n = 1; n <= k; n++)
        {
            int eat = slices[index] + dp1[index + 2][n - 1];
            int notEat = dp1[index + 1][n];

            dp1[index][n] = max(eat, notEat);
        }
    }

    int case1 = dp1[0][k / 3];

    for (int index = k - 1; index >= 1; index--)
    {
        for (int n = 1; n <= k; n++)
        {
            int eat = slices[index] + dp2[index + 2][n - 1];
            int notEat = dp2[index + 1][n];

            dp2[index][n] = max(eat, notEat);
        }
    }
    int case2 = dp2[1][k / 3];

    return max(case1, case2);
}

int maxSizeSlices(vector<int> &slices)
{
    int k = slices.size();
    
    // int case1 = solve(0 ,k-2 ,  slices , k/3);
    // int case2 = solve(1 , k-1 , slices , k/3);
    // return max(case1 , case2);

    // vector<vector<int>> dp1(k, vector<int>(k, -1));
    // int case1 = solveByMemoization(0, k - 2, slices, k / 3, dp1);
    // vector<vector<int>> dp2(k, vector<int>(k, -1));
    // int case2 = solveByMemoization(1, k - 1, slices, k / 3, dp2);
    // return max(case1, case2);

    return solveByTabulation(slices);
}

int main()
{
    vector<int> ques = {8, 9, 8, 6, 1, 1};
    cout << maxSizeSlices(ques);
    return 0;
}