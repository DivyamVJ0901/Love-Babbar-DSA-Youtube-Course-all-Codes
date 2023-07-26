#include <bits/stdc++.h>
using namespace std;

// USING RECURSION
int solveByRec(vector<vector<int>> &mat, int i, int j, int &maxi)
{
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    int right = solveByRec(mat, i + 1, j, maxi);       // Right me sirf row num increase hoga
    int diagnol = solveByRec(mat, i + 1, j + 1, maxi); // Diagnol me col num and row num increase hoge
    int down = solveByRec(mat, i, j + 1, maxi);        // Down me sirf col num increase hoga

    if (mat[i][j] == 1)
    {
        int ans = min(right, min(diagnol, down)) + 1;
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}

// USING MEMOIZATION
int solveByMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
{
    if (i >= mat.size() || j >= mat[0].size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solveByMem(mat, i + 1, j, maxi, dp);       // Right me sirf row num increase hoga
    int diagnol = solveByMem(mat, i + 1, j + 1, maxi, dp); // Diagnol me col num and row num increase hoge
    int down = solveByMem(mat, i, j + 1, maxi, dp);        // Down me sirf col num increase hoga

    if (mat[i][j] == 1)
    {
        dp[i][j] = min(right, min(diagnol, down)) + 1;
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    else
        return dp[i][j] = 0;
}

// USING TABULATION
int solveByTab(vector<vector<int>> &mat, int &maxi)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base case ki jarurat nahi h kyuki Base case me 0 hi return krna hai aur yaha pe already 0 se hi initialised hai

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1];       // Right me sirf row num increase hoga
            int diagnol = dp[i + 1][j + 1]; // Diagnol me col num and row num increase hoge
            int down = dp[i + 1][j];        // Down me sirf col num increase hoga

            if (mat[i][j] == 1)
            {
                dp[i][j] = min(right, min(diagnol, down)) + 1;
                maxi = max(maxi, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return dp[0][0];
}

// USING SPACE OPTIMISATION
int SolveBySpaceOpt(vector<vector<int>> &mat, int &maxi)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int right = curr[j + 1];   // Right me sirf row num increase hoga
            int diagnol = next[j + 1]; // Diagnol me col num and row num increase hoge
            int down = next[j];        // Down me sirf col num increase hoga

            if (mat[i][j] == 1)
            {
                curr[j] = min(right, min(diagnol, down)) + 1;
                maxi = max(maxi, curr[j]);
            }
            else
                curr[j] = 0;
        }
        next = curr;
    }
    return next[0];
}

int maximalSquare(int n, int m, vector<vector<int>> mat)
{
    // using recursion
    // int maxi = 0;
    // return solveByRec(mat, 0, 0, maxi);
    // return maxi;

    // using memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // int maxi = 0;
    // return solveByMem(mat, 0, 0, maxi, dp);
    // return maxi;

    // using Tabulation
    // int maxi = 0;
    // solveByTab(mat, maxi);
    // return maxi;

    // using Space Optimisation
    int maxi = 0;
    SolveBySpaceOpt(mat, maxi);
    return maxi;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
    cout << maximalSquare(0, 0, matrix);
    return 0;
}