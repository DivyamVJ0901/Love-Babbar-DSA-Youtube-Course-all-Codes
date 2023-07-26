// CODE TO CHECK WHETHER AN ARRAY IS SORTED ROTATED OR NOT
// Time Complexity = O(n)
// Space Complexity = O(1)
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums)
{
    int count = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
            count++;
    }

    if (nums[nums.size() - 1] > nums[0])
        count++;

    return count <= 1;
}

void PrintArray(vector<int> arr)
{
    cout<<"The array is : ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<<" ";
    }
    cout << endl;
}

int main()
{
    vector<int> Divyam;
    Divyam.push_back(21);
    Divyam.push_back(23);
    Divyam.push_back(43);
    Divyam.push_back(10);
    Divyam.push_back(15);
    PrintArray(Divyam);
    bool ans = check(Divyam);
    if (ans == 1)
        cout<<"Yes , The array is rotated and sorted.";
    else
        cout<<"No , The array is not rotated.";
    return 0;
}