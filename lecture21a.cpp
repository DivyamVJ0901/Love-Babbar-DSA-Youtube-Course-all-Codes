// CODE TO ROTATE AN ARRAY BY A PARTICULAR POSITION
// Time Complexity = O(n)
// Space Complexity = O(n)

#include <iostream>
#include <vector>
using namespace std;

void RotateArray(vector<int> &nums, int k)
{
    vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i];
    }
    nums = temp;
}

void PrintArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> Divyam;
    Divyam.push_back(21);
    Divyam.push_back(41);
    Divyam.push_back(22);
    Divyam.push_back(56);
    Divyam.push_back(43);
    Divyam.push_back(17);
    Divyam.push_back(10);
    Divyam.push_back(06);
    PrintArray(Divyam);

    cout << "The rotated array is : ";
    RotateArray(Divyam, 4);
    PrintArray(Divyam);
    return 0;
}
