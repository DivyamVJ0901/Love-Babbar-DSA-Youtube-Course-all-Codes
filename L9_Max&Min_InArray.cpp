// Maximum/Minimum in an array

// We can also perform this task using predefined functions.
// for example :
//              quantity 1 = max(quantity 1 , quantity 2)
//              quantity 1 = min(quantity 1 , quantity 2)

#include <iostream>
using namespace std;

int MaxValue(int num[], int n)
{
    int maxi = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        // maxi = max(maxi , num[i]);  Using a predefined function.
        if (num[i] > maxi)
        {
            maxi = num[i];
        }
    }
    return maxi;
}

int MinValue(int num[], int n)
{
    int mini = INT16_MAX;

    for (int i = 0; i < n; i++)
    {
        // mini = min(mini , num[i]); // Using a predefined function.
        if (num[i] < mini)
        {
            mini = num[i];
        }
    }
    return mini;
}

int main()
{

    int size;
    cout << "Enter the size of required array : " << endl;
    cin >> size;

    int num[5];
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    cout << "The maximum value is " << MaxValue(num, size) << endl;
    cout << "The minimum value is " << MinValue(num, size) << endl;

    return 0;
}