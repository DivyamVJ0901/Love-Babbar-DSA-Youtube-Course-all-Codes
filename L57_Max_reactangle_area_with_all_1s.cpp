#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextElement(int *heights, int n)
{
    // n = heights.size();
    stack<int> s;
    s.push(-1);

    vector<int> a(n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.top() != -1 && heights[s.top()] <= heights[i])
            s.pop();

        a[i] = s.top();
        s.push(i);
    }
    return a;
}

vector<int> prevElement(int *heights, int n)
{
    // n = heights.size();
    stack<int> s;
    s.push(-1);

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        if (s.top() != -1 && heights[s.top()] <= heights[i])
            s.pop();

        a[i] = s.top();
        s.push(i);
    }
    return a;
}

int LargestAreaInRectangle(int *heights, int size)
{
    vector<int> n(size);
    vector<int> p(size);

    n = nextElement(heights, size);
    p = nextElement(heights, size);

    int area = INT16_MIN;
    for (int i = 0; i < size; i++)
    {
        int length = heights[i];
        if (n[i] == -1)
            n[i] = size;

        int width = n[i] - p[i] - 1;
        int newArea = max(area, newArea);
    }
    return area;
}

int main()
{
    
    return 0;
}