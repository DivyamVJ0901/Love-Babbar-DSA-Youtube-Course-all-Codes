// // CODE TO GET SUBSETS OF A SET
// #include <iostream>
// #include <vector>
// using namespace std;

// void Solve(vector<int> &arr, vector<int> &output, int index, vector<vector<int>> &ans)
// {
//     // base case
//     if (index >= arr.size())
//     {
//         ans.push_back(output);
//         return;
//     }
//     // exclude
//     Solve(arr, output, index + 1, ans);

//     // include
//     output.push_back(arr[index]);
//     Solve(arr, output, index + 1, ans);
// }

// vector<vector<int>> Subsets(vector<int> &arr)
// {
//     vector<vector<int>> ans;
//     vector<int> output;
//     int index = 0;
//     Solve(arr, output, index, ans);
//     return ans;
// }

// void PrintArray(vector<int> v)
// {
//     for (int i = 0; i < v.size(); i++)
//         cout << v[i] << " ";
//     cout << endl;
// }

// void Print2DArray(vector<vector<int>> vec)
// {
//     for (int i = 0; i < vec.size(); i++)
//     {
//         for (int j = 0; j < vec.size(); j++)
//             cout << vec[i][j] << endl;
//     }
// }
// int main()
// {
//     vector<int> a = {1, 2, 3};
//     cout << "The input array is : ";
//     PrintArray(a);
//     vector<vector<int>> Ans = Subsets(a);
//     Print2DArray(Ans);
//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subarrays(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> result;

    // Generate all subarrays
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> subarray;
            for (int k = i; k <= j; k++)
            {
                subarray.push_back(nums[k]);
            }
            result.push_back(subarray);
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subarrays(nums);

    // Print all subarrays
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
