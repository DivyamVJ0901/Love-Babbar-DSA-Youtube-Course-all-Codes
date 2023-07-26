// BASIC INPUT OUTPUT CODE FOR 2D ARRAY
#include <iostream>
using namespace std;

int main()
{
    // int m, n;
    // cin >> m >> n;
    // Creating a 2D array
    // int Divyam[m][n];
    // Taking input--->>ROW WISE
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << "Enter the element of row no. " << i << " and column no. " << j << " : ";
    //         cin >> Divyam[i][j];
    //     }
    // }
    // cout << "Taking another input : " << endl;
    // // Taking input--->>COLUMN WISE
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << "Enter the element of row no. " << i << " and column no. " << j << " : ";
    //         cin >> Divyam[j][i];
    //     }
    // }

    // cout << "The matrix row wise is : " << endl;
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << Divyam[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "The matrix column wise is : " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << Divyam[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    // int a , b , c , d , e ,f , g , h , i , j , k , l , m , n , o ,p;
    // cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
    // int arr[3][4] = {{a , b , c , d} , {e , f , g ,h} , {i , j ,k , l}};
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int Dogesh[4][4] = {{1, 2, 1, 2}, {8, 1, 2, 3}, {5, 4, 8, 2}, {3, 6, 9, 4}};

    cout << "The marix is : " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << Dogesh[i][j] << " ";
        cout << endl;
    }

    int n, m;
    cin >> n >> m;
    int Vimdhayak_Ji[n][m];
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cin >> Vimdhayak_Ji[i][j];
    // }
    cout << "The another matrix is : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << Vimdhayak_Ji[i][j] << " ";
        cout << endl;
    }

    return 0;
}