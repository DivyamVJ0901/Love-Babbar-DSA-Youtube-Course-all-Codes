#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> NextSmallerElement(vector<int> &arr, int n)
{
    stack<int> cheems;
    cheems.push(-1);

    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (cheems.top() >= arr[i])
            cheems.pop();
        result[i] = cheems.top();
        cheems.push(arr[i]);
    }
    return result;
}

void PrintArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    vector<int> Dogesh = {2, 1, 4, 3};
    PrintArray(Dogesh);
    vector<int> ans = NextSmallerElement(Dogesh, 4);
    PrintArray(ans);
    return 0;
}
