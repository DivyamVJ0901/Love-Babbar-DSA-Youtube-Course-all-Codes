#include <bits/stdc++.h>
using namespace std;

// USING RECURSION
int solve(vector<int> &nums, int curr, int prev)
{
    if (curr == nums.size())
        return 0;

    // inclusion
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
        include = 1 + solve(nums, curr + 1, curr);

    // exclusion
    int exclude = 0;
    exclude = solve(nums, curr + 1, prev);

    return max(include, exclude);
}

// USING MEMOIZATION
int solveByMemoization(vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
{
    // Base case
    if (curr == nums.size())
        return 0;

    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // inclusion
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
        include = 1 + solveByMemoization(nums, curr + 1, curr, dp);

    // exclusion
    int exclude = 0;
    exclude = solveByMemoization(nums, curr + 1, prev, dp);

    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}

// USING TABULATION
int solveByTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));

    // Yaha base case ko analyse karne ki jarurat nahi padegi kyuki already 0 se initialised hai

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev != -1 || nums[curr] > nums[prev])
                include = 1 + dp[curr + 1][curr + 1]; // curr + 1 krna padega col ko jisse invalid index naa bane

            int exclude = 0;
            exclude = dp[curr + 1][prev + 1];

            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

// USING SPACE OPTIMISATION
int solveBySO(vector<int> &nums)
{
    int n = nums.size();
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
                include = 1 + nextRow[curr + 1];

            int exclude = nextRow[prev + 1];

            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return currRow[0];
}


// USING DP WITH BINARY SEARCH
int OptimalSolution(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    vector<int> ans;
    ans.push_back(nums[0]);
    // Ab pehle element ko hum kisi se compare kar nahi skte so usko pehle hi ans array me push krdo

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > ans.back())
            ans.push_back(nums[i]);
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }
    return ans.size();
}

int lengthOfLIS(vector<int> &nums)
{
    // return solve(nums ,0,-1);
    // vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
    // return solveByMemoization(nums, 0, -1, dp);

    // return solveByTabulation(nums);

    // return solveBySO(nums);
    return OptimalSolution(nums);
}

int main()
{
    vector<int> ques = {5, 8, 3, 7, 9, 1};
    cout << lengthOfLIS(ques);
    return 0;
}