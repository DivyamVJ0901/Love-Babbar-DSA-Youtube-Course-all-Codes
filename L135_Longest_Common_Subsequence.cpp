#include <bits/stdc++.h>
using namespace std;

int solveByRec(string text1, string text2, int i, int j)
{
    if (i >= text1.length() || j >= text2.length())
        return 0;
    if (text1[i] == text2[j])
        return (1 + solveByRec(text1, text2, i + 1, j + 1));
    else
        return max(solveByRec(text1, text2, i + 1, j), solveByRec(text1, text2, i, j + 1));
}

int solveByMemoization(string text1, string text2, int i, int j, vector<vector<int>> &dp)
{
    int ans = 0;
    if (i >= text1.length() || j >= text2.length())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (text1[i] == text2[j])
        ans = (1 + solveByMemoization(text1, text2, i + 1, j + 1, dp));
    else
        ans = max(solveByMemoization(text1, text2, i + 1, j, dp), solveByMemoization(text1, text2, i, j + 1, dp));

    dp[i][j] = ans;
    return dp[i][j];
}

int solveByTabulation(string text1, string text2)
{
    int len1 = text1.length();
    int len2 = text2.length();
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

    int ans = 0;
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
                ans = (1 + dp[i + 1][j + 1]);
            else
                ans = max(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int solveBySpaceOpt(string text1, string text2)
{
    int len1 = text1.length();
    int len2 = text2.length();

    vector<int> curr(len2 + 1, 0);
    vector<int> next(len2 + 1, 0);

    int ans = 0;
    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
                ans = (1 + next[j + 1]);
            else
                ans = max(next[j], curr[j + 1]);
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int longestCommonSubsequence(string text1, string text2)
{
    // return solveByRec(text1 , text2 , 0 , 0);

    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));
    // return solveByMemoization(text1 , text2 , 0 , 0 , dp);

    // return solveByTabulation(text1 , text2);

    return solveBySpaceOpt(text1, text2);
}

int main()
{
    string sample1 = "acdef";
    string sample2 = "ace";
    cout << longestCommonSubsequence(sample1, sample2);
    return 0;
}