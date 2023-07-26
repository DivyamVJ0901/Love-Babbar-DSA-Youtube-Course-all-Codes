#include <bits/stdc++.h>
using namespace std;

vector<int> nextElement(vector<int> &heights, int n)
{
    n = heights.size();
    stack<int> s;
    s.push(-1);

    vector<int> a(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && heights[s.top()] >= heights[i])
            s.pop();

        a[i] = s.top();
        s.push(i);
    }
    return a;
}

vector<int> prevElement(vector<int> &heights, int n)
{
    n = heights.size();
    stack<int> s;
    s.push(-1);

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && heights[s.top()] >= heights[i])
            s.pop();

        a[i] = s.top();
        s.push(i);
    }
    return a;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> n(heights.size());
    vector<int> p(heights.size());

    n = nextElement(heights, heights.size());
    p = prevElement(heights, heights.size());

    int area = INT16_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int len = heights[i];

        if (n[i] == -1)
            n[i] = heights.size();

        int wid = n[i] - p[i] - 1;

        int newArea = len * wid;
        area = max(area, newArea);
    }
    return area;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int maxi = INT_MIN;

    vector<int> height(matrix[0].size(), 0);

    // Matrix me traverse krne ke liye
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < height.size(); j++)
        {
            // height array ko update krne ke liye ,, jisse histogram banega
            if (matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }

        maxi = max(maxi, largestRectangleArea(height));
    }
    return maxi;
}

int main()
{
    vector<vector<char>> ques = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(ques);
    return 0;
}