#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int b;

    int **Jagged_Array = new int *[a];
    for (int i = 0; i < a; i++)
    {
        
        cin >> b;
        Jagged_Array[i] = new int[b];
        cout << "Enter array elements : " << endl;
        for (int j = 0; j < b; j++)
            cin >> Jagged_Array[i][j];
    }

    cout << "The expected Jagged array is : " << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
            cout << Jagged_Array[i][j] << " ";
        cout << endl;
    }

    return 0;
}