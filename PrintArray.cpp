// Acessing an array using a function call.

#include <iostream>
using namespace std;

void Print_array(int arr[], int size)
{
    cout << "Printing an array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << "Printing Done." << endl;
}

int main()
{
    int size ;
    int first[10] = {5, 8, 4};
    size = 10;

    int second[10] = {0};
    size = 10;

    int third[15] = {50};
    for (int i = 0; i < 15; i++)
    {
        third[i] = 50;
    }

    Print_array(first, 10);
    Print_array(second, 10);
    Print_array(third, 10);

    int thirdsize = sizeof(third)/sizeof(int);
    cout<<"Size of third is "<<thirdsize<<endl;

    int secondsize = sizeof(second)/sizeof(int);
    cout<<"Size of second is "<<secondsize;

    return 0;
}