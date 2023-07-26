#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &base, vector<int> &nextBox)
{
    if ((nextBox[0] <= base[0]) && (nextBox[1] <= base[1]) && (nextBox[2] <= base[2]))
        return true;
    return false;
}

int solve(int n, vector<vector<int>> &cuboids)
{
    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || check(cuboids[curr], cuboids[prev]))
                include = cuboids[curr][2] + nextRow[curr + 1]; // As height ko maximise karna hai so , cuboids[0][2] = height add krenge hum

            int exclude = nextRow[prev + 1];

            currRow[prev + 1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

int maxHeight(vector<vector<int>> &cuboids)
{
    // STEP-1 :
    for (auto &a : cuboids)
        sort(a.begin(), a.end());

    // STEP-2 :
    sort(cuboids.begin(), cuboids.end());

    // LIS Logic
    return solve(cuboids.size(), cuboids);
}

int main()
{
    vector<vector<int>> cuboid = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    cout << maxHeight(cuboid);
    return 0;
}