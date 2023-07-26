#include <bits/stdc++.h>
using namespace std;

int pow(int &a, int n)
{
    if (n == 0 || a == 1)
        return 1;
    if (n == 1)
        return a;

    return a * pow(a, n - 1);
}
int vector_num(vector<int> &nums)
{
    int sum = 0;
    // reverse(nums.begin() , nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = nums[i] * pow(10, nums.size() - i - 1);
        sum += temp;
        cout<<temp<<" X "<<sum<<endl;
    }
    return sum;
}
int superPow(int a, vector<int> &b)
{
    long long arr_sum = 0;
    for (int i = 0; i < b.size(); i++)
    {
        int temp = pow(b[i], i);
        arr_sum += temp;
    }
    if (a == 1 || arr_sum == 0)
        return 1;

    return pow(a, arr_sum);
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    int ans = vector_num(arr);
    cout<<ans<<endl;
    return 0;
}