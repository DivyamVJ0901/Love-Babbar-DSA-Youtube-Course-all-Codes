#include <bits/stdc++.h>
using namespace std;

// BY RECURSION
int solveByRecursion(vector<int> &nums, int n)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[0];

    // right to left traverse kar rahe hai

    int include = solveByRecursion(nums, n - 2) + nums[n]; //  include ke case me nums[n] add hoga
    int exclude = solveByRecursion(nums, n - 1);           // exclude ke case me sum as it is rahega

    return max(include, exclude);
}

// BY MEMOIZATION
int solveByMemoization(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[0];

    if (dp[n] != -1)
        return dp[n];

    int include = solveByMemoization(nums, n - 2, dp) + nums[n];
    int exclude = solveByMemoization(nums, n - 1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
}

// BY TABULATION
int solveByTabulation(vector<int> &nums, int n, vector<int> &dp)
{
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }
    return dp[n - 1];
}

// BY SPACE OPTIMISATION
int solveBySpaceOPT(vector<int> &nums, int n)
{
    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        int include = prev2 + nums[i];
        int exclude = prev1;
        int ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    //  SOLVED BY RECURSION
    // int n = nums.size();
    // return solveByRecursion(nums , n-1);

    // SOLVED BY MEMOISATION
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solveByMemoization(nums, n - 1, dp);

    // SOLVED BY TABULATION
    // int n = nums.size();
    // vector<int> dp(n + 1, -1);
    // return solveByTabulation(nums, n - 1, dp);

    // SOLVE BY SPACE OPTIMIZATION
    // int n = nums.size();
    // return solveBySpaceOPT(nums, n - 1);
}

int main()
{
    vector<int> arr = {9, 9, 8, 2};
    cout << maximumNonAdjacentSum(arr);
    return 0;
}
