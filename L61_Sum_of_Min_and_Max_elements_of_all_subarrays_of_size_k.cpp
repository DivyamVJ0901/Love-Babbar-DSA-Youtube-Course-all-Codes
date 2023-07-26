#include <bits/stdc++.h>
using namespace std;

int sumOfMaximaAndMinima(int arr[], int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    int sum = 0;

    for (int i = k; i < n; i++)
    {
        sum += arr[maxi.front()] + arr[mini.front()];

        // Next Window

        // Removal
        while (!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();

        while (!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

        // Addition : (Same code copy paste from above)
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    // Last window ke liye
    sum += arr[maxi.front()] + arr[mini.front()];

    return sum;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};

    cout<<sumOfMaximaAndMinima(arr , 7 , 4);

    return 0;
}