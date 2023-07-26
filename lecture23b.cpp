// CODE FOR LINEAR SEARCH IN A 2D ARRAYs

#include <iostream>
#include <vector>
using namespace std;

bool isFound(int arr[][4], int key, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == key)
                return 1;
        }
    }
    return 0;
}

int main()
{

    int arr[3][4] = {{1, 2, 4, 8}, {4, 5, 3, 1}, {7, 2, 3, 0}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    int key;
    cout << "Enter key element : ";
    cin >> key;

    bool ans = isFound(arr, key, 3, 4);

    if (ans == 1)
        cout << "Element found." << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

// #include <iostream>
// using namespace std;

// int non_repeating_elements(int arr[], int n)
// {
//     int i, j;
//     int count = 1;
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             if (arr[i] == arr[j] && i != j)
//                 break;
//         }
//         if (j == n)
//         {
//             cout << "\nNon-repeating element [" << count << "]"
//                  << " : " << arr[i];
//             ++count;
//         }
//     }
// }
// int main()
// {
//     int a[8] = {1, 5, 6, 7, 1, 8, 5, 6};
//     non_repeating_elements(a, 8);
//     return 0;
// }
