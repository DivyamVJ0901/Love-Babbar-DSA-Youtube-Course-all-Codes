#include <bits/stdc++.h>
using namespace std;

// USING RECURSION
int solve(vector<int> &obs, int currPos, int currLane)
{
    int ans = INT_MAX;
    // Base case
    if (currPos == obs.size() - 1)
        return 0;

    if (obs[currPos + 1] != currLane)
        return solve(obs, currPos + 1, currLane);

    else
    {
        for (int i = 1; i <= 3; i++)
        {
            if ((currLane != i) && (obs[currPos] != i))
                ans = min(ans, 1 + solve(obs, currPos, i));
        }
    }
    return ans;
}

// USING TOP DOWN APPROACH
int solveByMemoization(vector<int> &obs, int currPos, int currLane, vector<vector<int>> &dp)
{
    int jumpCnt = INT_MAX;
    if (currPos == obs.size() - 1)
        return 0;

    if (dp[currPos][currLane] != -1)
        return dp[currPos][currLane];

    if (obs[currPos + 1] != currLane)
        return solveByMemoization(obs, currPos + 1, currLane, dp);

    else
    {
        for (int i = 1; i <= 3; i++)
        {
            if ((currLane != i) && (obs[currPos] != i))
                jumpCnt = min(jumpCnt, 1 + solveByMemoization(obs, currPos, i, dp));
            dp[currPos][currLane] = jumpCnt;
        }
        return dp[currPos][currLane];
    }
}

// USING BOTTOM UP APPROACH
int solveByTabulation(vector<int> &obs)
{
    int a = obs.size() - 1;
    vector<vector<int>> dp(4, vector<int>(obs.size(), INT_MAX));

    dp[0][a] = 0;
    dp[1][a] = 0;
    dp[2][a] = 0;
    dp[3][a] = 0;

    for (int currPos = a - 1; currPos >= 0; currPos--)
    {
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            if (obs[currPos + 1] != currLane)
                dp[currLane][currPos] = dp[currLane][currPos + 1];

            else
            {
                int jumpCnt = INT_MAX;
                for (int i = 1; i <= 3; i++)
                {
                    if ((currLane != i) && (obs[currPos] != i))
                        jumpCnt = min(jumpCnt, 1 + dp[i][currPos + 1]);
                }
                dp[currPos][currPos] = jumpCnt;
            }
        }
    }
    // Teeno me se minimum ans nikalna hai
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}

// USING SPACE OPTIMISATION
int solveBySO(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;

    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int currPos = n - 1; currPos >= 0; currPos--)
    {
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            if (obstacles[currPos + 1] != currLane)
                curr[currLane] = next[currLane];

            else
            {
                int jumpCnt = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if ((currLane != i) && (obstacles[currPos] != i))
                        jumpCnt = min(jumpCnt, 1 + next[i]);
                }
                curr[currLane] = jumpCnt;
            }
        }
        next = curr;
    }
    return min(next[2], min(1 + next[1], 1 + next[3]));
}
int minSidewaysJumps(vector<int> &obs)
{
    // Frog starting from 0 position and lane no. 2

    // Using recursion
    // return solve(obs, 0, 2);

    // Using Memoization
    // int n = obs.size() - 1;
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // return solveByMemoization(obs, 0, 2, dp);

    // Using Tabulation
    // return solveByTabulation(obs);

    return solveBySO(obs);
}

int main()
{
    vector<int> ques = {0, 1, 2, 3, 0};
    cout << minSidewaysJumps(ques);
    return 0;
}