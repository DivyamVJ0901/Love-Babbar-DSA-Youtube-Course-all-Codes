// Basic array introduction and basic programme 

#include<iostream>
using namespace std;

int main(){

    // Initializing an array with 0

    int arr1[10] = {0};

    for (int i = 0; i < 10; i++)
    {
        cout<<"The value of element No. " <<i<<" is "<<arr1[i]<<endl;  
    }
    
    cout<<endl;

    // In the following case , only first element will be initialized to 23 and rest of the elements will be inialized to 0.

    int arr2[10]={23,47}; 

    for (int i = 0; i < 10; i++)
    {
        cout<<"The value of element No. "<<i<<" is "<<arr2[i]<<endl;
    }
    cout<<endl;
    

    // If we want that all the elements are initialized to 23 . Then we use a for loop as in the following :

    for (int i = 0; i < 10; i++)
    {                                                                
        arr2[i]=23;
        cout<<"The value of element Np. "<<i<< " is "<<arr2[0]<<endl;
    }
    return 0;
}