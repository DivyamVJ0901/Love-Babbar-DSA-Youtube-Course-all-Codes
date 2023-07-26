#include <bits/stdc++.h>
using namespace std;

bool solveByRec(string str, string pattern, int i, int j)
{
    // Base cases
    if (i < 0 && j < 0)
        return true;
    if (i >= 0 && j < 0)
        return false;
    if (i < 0 && j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (pattern[k] != '*')
                return false;
        }
        return true;
    }
    bool ans = 0;
    // Match
    if (str[i] == pattern[j] || (pattern[j] == '?'))
    {
        ans = solveByRec(str, pattern, i - 1, j - 1);
    }
    else if (pattern[j] == '*')
    {
        ans = ((solveByRec(str, pattern, i, j - 1)) || (solveByRec(str, pattern, i - 1, j)));
    }
    else
        ans = false;
    return ans;
}

bool solveByMemoization(string str, string pattern, int i, int j, vector<vector<int>> &dp)
{
    // Base cases
    if (i == 0 && j == 0)
        return true;

    if (i > 0 && j == 0)
        return false;

    if (i == 0 && j > 0)
    {
        for (int k = 1; k <= j; k++)
        {
            if (pattern[k - 1] != '*')
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];
    bool ans = false;
    // Match
    if (str[i - 1] == pattern[j - 1] || (pattern[j - 1] == '?'))
        ans = solveByMemoization(str, pattern, i - 1, j - 1, dp);
    else if (pattern[j - 1] == '*')
        ans = ((solveByMemoization(str, pattern, i, j - 1, dp)) || (solveByMemoization(str, pattern, i - 1, j, dp)));
    else
        ans = false;

    dp[i][j] = ans;
    return dp[i][j];
}

bool solveByTabulation(string str, string pattern)
{
    vector<vector<int>> dp(str.length() + 1, vector<int>(pattern.length() + 1, 0));
    dp[0][0] = true;

    for (int j = 1; j <= pattern.length(); j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (pattern[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for (int i = 1; i <= str.length(); i++)
    {
        for (int j = 1; j <= pattern.length(); j++)
        {
            if (str[i - 1] == pattern[j - 1] || (pattern[j - 1] == '?'))
                dp[i][j] = dp[i - 1][j - 1];
            else if (pattern[j - 1] == '*')
                dp[i][j] = ((dp[i - 1][j]) || (dp[i][j - 1]));
            else
                dp[i][j] = false;
        }
    }
    return dp[str.length()][pattern.length()];
}

bool solveBySO(string str, string pattern)
{
    vector<int> prev(pattern.length() + 1, 0);
    vector<int> curr(pattern.length() + 1, 0);
    prev[0] = true;
    for (int j = 1; j <= pattern.length(); j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (pattern[k - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }

    for (int i = 1; i <= str.length(); i++)
    {
        for (int j = 1; j <= pattern.length(); j++)
        {
            if (str[i - 1] == pattern[j - 1] || (pattern[j - 1] == '?'))
                curr[j] = prev[j - 1];
            else if (pattern[j - 1] == '*')
                curr[j] = ((prev[j]) || (curr[j - 1]));
            else
                curr[j] = false;
        }
        prev = curr;
    }
    return prev[pattern.length()];
}

bool isMatch(string s, string p)
{
    // return solveByRec(s, p, s.length() - 1, p.length() - 1);

    // vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
    // return solveByMemoization(s, p, s.length() - 1, p.length() - 1, dp);

    // return solveByTabulation(s, p);

    return solveBySO(s, p);
}

int main()
{
    string s = "abcde";
    string p = "a*c?e";
    if (isMatch(s, p))
        cout << "Valid Pattern";
    else
        cout << "Invalid Pattern";
    return 0;
}