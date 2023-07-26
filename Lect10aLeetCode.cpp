// QUES - 1) You have been given an integer array of size N. When N is equal to 2m+1.Now , in the given arraylist ."M" numbers are present
// twice and one number is present only once.

// You need to find out and return that number which is unique in the arraylist.

/*
Yaha Ques ye kehra hai ki hmaare paas koi 3 numbers aise hai jo array me 2 - 2 baar aa rahe hai aur koi ek number aisa hai jo bas 1 hi
baar aa raha hai. To hame vo number btana hai ki konsa number hai jo ek hi baar array me aa rha hai.
*/

// MY CODE :-
// #include <iostream>
// using namespace std;

// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
//     int count = 1;
//     int i = 0;
//     while (count < 10)
//     {
//         if (arr[i] == arr[i + count])
//         {
//             cout << "The repeated element is : " << arr[i];
//             i++;
//             count++;
//         }
//     }

//     return 0;
// }

// LOVE BABBAR CODE :-(Using XOR operators)
// #include<iostream>
// using namespace std;

// int main(){
//     int arr[7] = {2,3,1,6,3,6,2};

//     int ans;
//     for (int i = 0; i < 7; i++)
//     {
//         ans = ans^arr[i];
//     }

//     return ans;
//     cout<<ans;
//     return 0;
// }

// QUES - 2) same ques but this time we have to print repeatd number
// #include <iostream>
// using namespace std;

// int DuplicateNum(int arr[], int n)
// {
//     int ans = 0;

//     for (int i = 0; i < n; i++)
//     {
//         ans = ans ^ arr[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         ans = ans ^ i;
//     }

//     return ans;
// }

// int main()
// {
//     int arr[5] = {1, 3, 45, 45, 67};
//     DuplicateNum(arr, 5);
//     return 0;
// }

// QUES-3) Find all the repeated numbers in array.(HW)

// QUES-4) Finding Intersection of arrays (Common element)
#include <iostream>
using namespace std;

void IntersectArray(int arr1[], int arr2[], int n)
{
    int i = 0;
    int j = 0;

    int ans;

    while (i < n && j < n)
    {
        if (arr1[i] == arr2[j])
        {
            cout<<ans;
        }
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        else{
            j++;
        }
    }
}

int main()
{
    int arr1[5] = {1, 2, 2, 3, 4};
    int arr2[5] = {3, 4, 7, 8, 10};

    IntersectArray(arr1 , arr2 , 5);

    return 0;
}