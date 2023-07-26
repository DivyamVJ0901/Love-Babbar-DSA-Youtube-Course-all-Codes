#include <bits/stdc++.h>
using namespace std;

int choclateDistribution(vector<int> arr, int N, int M)
{
    sort(arr.begin(), arr.end());

    int i = 0;
    int j = M - 1;
    int mini = INT_MAX;

    while (j < arr.size())
    {
        int diff = arr[j++] - arr[i++];
        mini = min(mini, diff);
    }
    return mini;
}

int main()
{
    vector<int> ques = {3, 4, 1, 9, 56, 7, 9, 12};
    cout << choclateDistribution(ques, 8, 5);
    return 0;
}