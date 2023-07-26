// SUM OF 2 ARRAYS
// Time Complexity = O(n+m)
// Space Complexity = O(n+m)

#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> cheems)
{

    int s = 0;
    int e = cheems.size() - 1;

    while (s <= e)
    {
        swap(cheems[s], cheems[e]);
        s++;
        e--;
    }
    return cheems;
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    int carry = 0;
    int sum, v1, v2, result;
    while (i >= 0 && j >= 0)
    {
        v1 = a[i];
        v2 = b[j];

        sum = v1 + v2 + carry;

        carry = sum / 10;
        result = sum % 10;
        ans.push_back(result);
        i--;
        j--;
    }

    while (i >= 0)
    {
        sum = a[i] + carry;
        carry = sum / 10;
        result = sum % 10;
        ans.push_back(result);
        i--;
    }
    while (j >= 0)
    {
        sum = b[j] + carry;
        carry = sum / 10;
        result = sum % 10;
        ans.push_back(result);
        j--;
    }

    while (carry != 0)
    {
        sum = carry;
        carry = sum / 10;
        result = sum % 10;
        ans.push_back(result);
    }
    return ans;
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
    Divyam.push_back(12);
    Divyam.push_back(8);
    Divyam.push_back(5);

    vector<int> Megha;
    Megha.push_back(9);
    Megha.push_back(10);
    Megha.push_back(6);

    cout << "The first array is : ";
    PrintArray(Divyam);

    cout << "The second array is : ";
    PrintArray(Megha);

    vector<int > Dogesh = findArraySum(Divyam, 3, Megha, 3);
    vector<int > vimdhayak_ji = reverse(Dogesh);

    cout << "The array formed by the sum of elements of 2 arrays is : ";
    PrintArray(vimdhayak_ji);
    return 0;
}