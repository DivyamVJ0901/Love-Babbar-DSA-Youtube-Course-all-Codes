#include <bits/stdc++.h>
using namespace std;

// USING RECURSION
int solve(int index, int commomDiff, vector<int> &nums)
{
    if (index < 0)
        return 0;

    int ans = 0;
    for (int j = index - 1; j >= 0; j--)
    {
        if (nums[index] - nums[j] == commomDiff)
            ans = max(ans, 1 + solve(j, commomDiff, nums));
    }
    return ans;
}

int longestArithSeqLength(vector<int> &nums)
{
    if (nums.size() <= 2)
        return 0;

    unordered_map<int, int> dp(nums.size() + 1);
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
            ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums));
    }
    return ans;
}

int solveByMemoization(int index, int commomDiff, vector<int> &nums, unordered_map<int, int> dp[])
{
    if (index < 0)
        return 0;

    if (dp[index].count(commomDiff))
        return dp[index][commomDiff];

    int ans = 0;
    for (int j = index - 1; j >= 0; j--)
    {
        if (nums[index] - nums[j] == commomDiff)
            ans = max(ans, 1 + solveByMemoization(j, commomDiff, nums, dp));
    }
    dp[index][commomDiff] = ans;
    return dp[index][commomDiff];
}


int longestArithSeqLengthByMemoization(vector<int> &nums)
{
    if (nums.size() <= 2)
        return 0;

    unordered_map<int, int> dp[nums.size() + 1];
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
            ans = max(ans, 2 + solveByMemoization(i, nums[j] - nums[i], nums ,dp));
    }
    return ans;
}

int longestArithSeqLengthByTabulation(vector<int> &nums)
{
    if (nums.size() <= 2)
        return nums.size();

    unordered_map<int, int> dp[nums.size() + 1];

    int ans = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0 ; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            int cnt = 1;

            if(dp[j].count(diff))
                cnt = dp[j][diff];
            
            dp[i][diff] = 1 + cnt;
            
            ans = max(ans , dp[i][diff]);
        }
    }
    return ans;
}

int longestArithmeticSub(vector<int> &nums)
{

    // using Recursion
    // return longestArithSeqLength(nums);

    // using Memoization
    // return longestArithSeqLengthByMemoization(nums);

    // using Tabulation
    return longestArithSeqLengthByTabulation(nums);   
}

int main()
{
    vector<int> ques = {1, 7, 10, 13, 14, 19};
    cout << longestArithmeticSub(ques);
    return 0;
}