// SCOPES IN ARRAY

#include <iostream>
using namespace std;

void updateArray(int arr[], int size)
{
    cout << "We are in our update function." << endl;

    arr[0]=7;

    // Printing an array
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "We are going to our main function." << endl;
}

int main()
{
    int arr[3] = {5, 12, 13};

    updateArray(arr,  3);
    
    // Printing an array
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // int size;
    // int arr[size
    return 0;
}

/*
In 38th line , we update its 0th value and changed it from 5 to 7
We have a doubt here that when we declare any variable outside our main function
and redeclare it into main function with some other value, then we get two diffrent values in output.
But in case of array , if we update its any iteration value then it is updated in main function too.
Here we don't give array to our main function  , we give its memory address to function.
SO BE AWARE THAT WHEN WE ARE DEALING WITH FUNCTIONS , DONT CHANGE ARRAY
*/