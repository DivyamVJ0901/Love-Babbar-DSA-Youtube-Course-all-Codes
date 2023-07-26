#include <iostream>
#include <stack>
#include <vector>
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

int LargestAreaOfHistogram(vector<int> &heights)
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

int main()
{
    vector<int> Divyam = {2, 1, 5, 6, 2, 3};

    cout <<"The maximum area is : " <<LargestAreaOfHistogram(Divyam);

    return 0;
}