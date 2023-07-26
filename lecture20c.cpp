// CODE TO MOVE ALL NON ZERO ELEMENTS TO LEFT AND ALL ZEROS TO RIGHT
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void MoveZeroes(vector<int> &arr)
{
    int nonZero = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[nonZero]);
            nonZero++;
        }
    }
}

void PrintArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    vector<int> Divyam;
    Divyam.push_back(23);
    Divyam.push_back(00);
    Divyam.push_back(07);
    Divyam.push_back(00);
    Divyam.push_back(00);
    Divyam.push_back(78);
    Divyam.push_back(89);
    Divyam.push_back(00);

    cout << "The array is : ";
    PrintArray(Divyam);
    MoveZeroes(Divyam);
    cout << endl;
    cout<<"The operated array is : ";
    PrintArray(Divyam);

    return 0;
}