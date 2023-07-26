#include<iostream>
using namespace std;

int main()
{
    int n , m;
    cin>>n>>m;

    // CREATING A 2D ARRAY IN HEAP
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];

    // Taking input 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin>>arr[i][j];
    }


    // Taking output 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    
    // Releasing memory
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
            delete [] arr[i];
        delete [] arr;
    }
    return 0;
}