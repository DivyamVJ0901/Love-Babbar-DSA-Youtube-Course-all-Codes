
// BINARY SEARCH

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;

    // int mid = (s + e) / 2;
    
    // Yaha pe ek bahut badi mistake hai , hame pta hai ki jo integer value hoti hai uski max value 2^31-1 hoti hai
    // to dono s aur e ki max value 2^31 - 1 hogi to jab hum 'mid' intger calculate kar rahe hai to mid ki value range
    // se bahar jaa rahi hai which is not possible . So to avoid this , instead of writing (s+e)/2 we write s/2 + (e-s)/2 .....

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        if (key > arr[mid])
        {
            s = mid + 1;
        }

        if (key < arr[mid])
        {
            e = mid - 1;
        }

        mid = (s + e) / 2;
    }

    return -1;
}

int main()
{
    int even[8] = {2, 7, 15, 18, 53, 62, 78, 94};
    int odd[7] = {12, 17, 51, 81, 83, 621, 788};

    int evenindex = BinarySearch(even, 8, 78);
    int oddindex = BinarySearch(odd, 7, 20);

    cout << "The index of 78 is " << evenindex << endl;
    cout << "The index of 20 is " << oddindex << endl;

    return 0;
}