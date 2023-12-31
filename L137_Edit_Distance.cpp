#include <bits/stdc++.h>
using namespace std;

int solveByRec(string word1, string word2, int i, int j)
{
    if (i == word1.length())
        return word2.length() - j;
    if (j == word2.length())
        return word1.length() - i;

    int ans = 0;
    if (word1[i] == word2[j])
        ans = solveByRec(word1, word2, i + 1, j + 1);
    else
    {
        int insertAns = 1 + solveByRec(word1, word2, i, j + 1);
        int deleteAns = 1 + solveByRec(word1, word2, i + 1, j);
        int replaceAns = 1 + solveByRec(word1, word2, i + 1, j + 1);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return ans;
}

int solveByMemoization(string word1, string word2, int i, int j, vector<vector<int>> &dp)
{
    if (i == word1.length())
        return word2.length() - j;
    if (j == word2.length())
        return word1.length() - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (word1[i] == word2[j])
        ans = solveByMemoization(word1, word2, i + 1, j + 1, dp);
    else
    {
        int insertAns = 1 + solveByMemoization(word1, word2, i, j + 1, dp);
        int deleteAns = 1 + solveByMemoization(word1, word2, i + 1, j, dp);
        int replaceAns = 1 + solveByMemoization(word1, word2, i + 1, j + 1, dp);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveByTabulation(string word1, string word2)
{
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

    for (int j = 0; j < word2.length(); j++)
        dp[word1.length()][j] = word2.length() - j;

    for (int i = 0; i < word1.length(); i++)
        dp[i][word2.length()] = word1.length() - i;

    for (int i = word1.length() - 1; i >= 0; i--)
    {
        for (int j = word2.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if (word1[i] == word2[j])
                ans = dp[i + 1][j + 1];
            else
            {
                int insertAns = 1 + dp[i][j + 1];
                int deleteAns = 1 + dp[i + 1][j];
                int replaceAns = 1 + dp[i + 1][j + 1];
                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int solveBySO(string word1, string word2)
{
    // vector<vector<int>> dp(word1.length() + 1 , vector<int>(word2.length() + 1 , 0));

    vector<int> curr(word2.length() + 1, 0);
    vector<int> next(word2.length() + 1, 0);
    for (int j = 0; j < word2.length(); j++)
        next[j] = word2.length() - j;

    // for(int i = 0 ; i < word1.length() ; i++)
    // dp[i][word2.length()] = word1.length() - i;

    for (int i = word1.length() - 1; i >= 0; i--)
    {
        for (int j = word2.length() - 1; j >= 0; j--)
        {
            // Most important part of this ques
            curr[word2.length()] = word1.length() - i;
            int ans = 0;
            if (word1[i] == word2[j])
                ans = next[j + 1];
            else
            {
                int insertAns = 1 + curr[j + 1];
                int deleteAns = 1 + next[j];
                int replaceAns = 1 + next[j + 1];
                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}

int minDistance(string word1, string word2)
{
    // return solveByRec(word1 , word2 , 0 , 0);

    // vector<vector<int>> dp(word1.length() + 1 , vector<int>(word2.length() + 1 , -1));
    // return solveByMemoization(word1 , word2 , 0 , 0 ,dp);

    // return solveByTabulation(word1 , word2);

    if (word1.length() == 0)
        return word2.length();
    if (word2.length() == 0)
        return word1.length();                                                                                                                                              
    return solveBySO(word1, word2);
}

int main()
{
    string ques1 = "horse";
    string ques2 = "ros";
    cout << minDistance(ques1, ques2);
    return 0;
}