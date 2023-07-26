// PRINTING THE SUM OF ARRAY ELEMENTS. 

// #include<iostream>
// using namespace std;

// int main(){
//     int n1, n2 , n3 ,n4 ,n5;
//     cin>>n1>>n2>>n3>>n4>>n5;
//     int arr[5] = {n1 , n2 , n3 , n4 , n5};
//     // int arr[5] = {52,65,48,20,78};
//     int sum = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         sum = sum + arr[i];
//     }
//     cout<<"Sum of Array elements is : "<<sum<<endl;
//     return 0;
// }

// REVERSING AN ARRAY IN ALTERNATE MANNER 

// #include<iostream>
// using namespace std;

// void ReverseArray(int arr[], int n)
// {
//     int start = 0;
//     int end = n - 1;
//     cout << "The Reversed array is : ";
//     while (start <= end)
//     {
//         swap(arr[start], arr[end]);
//         start ++ ;
//         ++ start ;
//         end--;
//         --end;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main(){
//     int arr1[6] = {2 , 4 , 6 , 8 , 10 , 12};
//     int arr2[7] = {2 , 4 , 6 , 8 , 10 , 12 , 14};

//     ReverseArray(arr1 , 6);
//     ReverseArray(arr2 , 7 );
//     return 0;
// }
