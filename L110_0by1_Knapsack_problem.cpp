#include <bits/stdc++.h>
using namespace std;

// USING RECURSION
int solve(vector<int> &weight, vector<int> &value, int index, int cap)
{
    if (index == 0)
    {
        if (weight[index] <= cap)
            return value[index];
        else
            return 0;
    }

    int inc = 0;
    if (weight[index] <= cap)
        inc = value[index] + solve(weight, value, index - 1, cap - weight[index]);

    int exc = solve(weight, value, index - 1, cap);

    return max(inc, exc);
}

// USING MEMOIZATION
int solveByMemoization(vector<int> &weight, vector<int> &value, int index, int cap, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[index] <= cap)
            return value[index];
        else
            return 0;
    }

    if (dp[index][cap] != -1)
        return dp[index][cap];

    int inc = 0;
    if (weight[index] <= cap)
        inc = value[index] + solveByMemoization(weight, value, index - 1, cap - weight[index], dp);

    int exc = solveByMemoization(weight, value, index - 1, cap, dp);

    dp[index][cap] = max(inc, exc);
    return dp[index][cap];
}

// USING TABULATION
int solveByTabulation(vector<int> &weight, vector<int> &value, int index, int cap)
{
    // STEP 1 : Creation of 2D DP array
    vector<vector<int>> dp(index, vector<int>(cap + 1, -1));

    // STEP 2: Analyze of base cases
    for (int w = weight[0]; w <= cap; w++)
    {
        if (weight[0] <= cap)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    // STEP 3 : For loop for remaining recursive calls
    for (int i = 1; i < index; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            int inc = 0;
            if (weight[i] <= j)
                inc = value[i] + dp[i - 1][j - weight[i]];
            int exc = dp[i - 1][j];
            dp[i][j] = max(inc, exc);
        }
    }
    return dp[index - 1][cap]; 
}

// USING SPACE OPTIMIZATION
int solveBySO(vector<int> &weight, vector<int> &value, int index, int cap)
{
    // STEP 1 : Creation of 2D DP array
    vector<int> prev(cap + 1, 0);
    vector<int> curr(cap + 1, 0);

    // STEP 2: Analyze of base cases
    for (int w = weight[0]; w <= cap; w++)
    {
        if (weight[0] <= cap)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    // STEP 3 : For loop for remaining recursive calls
    for (int i = 1; i < index; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            int inc = 0;
            if (weight[i] <= j)
                inc = value[i] + prev[j - weight[i]];
            int exc = prev[j];
            curr[j] = max(inc, exc);
        }
        prev = curr;
    }
    return prev[cap];
}

// USING SUPER SPACE OPTIMISATION (only curr array will be used)
int solveBySuperSO(vector<int> &weight, vector<int> &value, int index, int cap)
{
    // STEP 1 : Creation of 2D DP array
    vector<int> curr(cap + 1, 0);

    // STEP 2: Analyze of base cases
    for (int w = weight[0]; w <= cap; w++)
    {
        if (weight[0] <= cap)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    // STEP 3 : For loop for remaining recursive calls
    for (int i = 1; i < index; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            int inc = 0;
            if (weight[i] <= j)
                inc = value[i] + curr[j - weight[i]];
            int exc = curr[j];
            curr[j] = max(inc, exc);
        }
    }
    return curr[cap];
}

int knapSack(vector<int> &weight, vector<int> &value, int index, int cap)
{
    // Using Rec
    // return solve(weight, value, index - 1, cap);

    // Using Mem
    // vector<vector<int>> dp(index, vector<int>(cap + 1, -1));
    // return solveByMemoization(weight, value, index - 1, cap, dp);

    // Using Tabulation
    // return solveByTabulation(weight, value, index, cap);

    // Using Space Optimisation
    // return solveBySO(weight, value, index, cap);s

    // Using Super Space Optimisation 
    return solveBySuperSO(weight, value, index, cap);
}

int main()
{
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};

    cout << "The max value is : " << knapSack(wt, val, 4, 5);
    return 0;
}