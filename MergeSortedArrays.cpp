// CODE TO MERGE TW0 SORTED ARRAYS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
{
    cout << "The merged array of 2 sorted array is : ";
    int i = 0, j = 0, k = 0;
    int n = arr1.size();
    int m = arr2.size();
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else if (arr1[i] > arr2[j])
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    while (i < n)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    while (j < m)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
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
    vector<int> cheems;
    cheems.push_back(01);
    cheems.push_back(06);
    cheems.push_back(10);
    cheems.push_back(23);
    cheems.push_back(43);
    cheems.push_back(56);

    vector<int> Vimdhayak;
    Vimdhayak.push_back(15);
    Vimdhayak.push_back(21);
    Vimdhayak.push_back(45);
    Vimdhayak.push_back(63);

    cout << "The Printed array is : ";
    PrintArray(cheems);
    cout << "The Printed array is : ";
    PrintArray(Vimdhayak);

    vector<int> Dogesh(cheems.size() + Vimdhayak.size());
    merge(cheems , Vimdhayak ,Dogesh);
    PrintArray(Dogesh);

    return 0;
}
