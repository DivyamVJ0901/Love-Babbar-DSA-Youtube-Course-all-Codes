#include <bits/stdc++.h>
using namespace std;

int solveByRec(int index, vector<int> &nums, int target)
{
    if (target < 0 || (index > nums.size()))
        return 0;
    if (target == 0)
        return 1;

    bool inc = solveByRec(index + 1, nums, target - nums[index]);
    bool exc = solveByRec(index + 1, nums, target);

    return (inc || exc);
}

int solveByMemoization(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
{
    if (target < 0 || (index > nums.size()))
        return 0;
    if (target == 0)
        return 1;

    if (dp[index][target] != -1)
        return dp[index][target];

    bool inc = solveByMemoization(index + 1, nums, target - nums[index], dp);
    bool exc = solveByMemoization(index + 1, nums, target, dp);

    dp[index][target] = inc || exc;
    return dp[index][target];
}

bool solveByTabulation(int index, vector<int> &nums, int total)
{
    vector<vector<int>> dp(nums.size(), vector<int>(total + 1, 0));
    for (int i = 0; i < nums.size(); i++)
        dp[i][0] = 1;
    for (int index = nums.size() - 1; index >= 0; index--)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            bool inc = 0;
            if (target - nums[index] >= 0)
                inc = dp[index + 1][target - nums[index]];
            bool exc = dp[index + 1][target];
            dp[index][target] = inc or exc;
        }
    }
    return dp[0][total / 2];
}

bool solveBySO(int index, vector<int> nums, int total)
{
    vector<int> curr(total/2 + 1, 0);
    vector<int> next(total/2 + 1, 0);

    curr[0] = 1;
    next[0] = 1;

    for (int index = nums.size() - 1; index >= 0; index--)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            bool inc = 0;
            if (target - nums[index] >= 0)
                curr[target] = (next[target - nums[index]] || next[target]);
        }
        next = curr;
    }
    return next[total/2];
}

bool canPartition(vector<int> &nums)
{
    int total_sum = 0;
    for (int i = 0; i < nums.size(); i++)
        total_sum += nums[i];
    if (total_sum % 2 != 0)
        return false;

    // return solveByRec(0, nums, total_sum / 2);

    // vector<vector<int>> dp(nums.size(), vector<int>(total_sum / 2 + 1, -1));
    // return solveByMemoization(0, nums, total_sum / 2, dp);

    // return solveByTabulation(0 , nums , total_sum/2);

    return solveBySO(0 , nums , total_sum/2);
}

int main()
{
    vector<int> ques = {1, 5, 11, 5};
    if (canPartition(ques))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}