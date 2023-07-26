#include <iostream>
using namespace std;

void update(int *p)
{
    *p = *p + 1;
    p = p + 1;
    cout << *p << endl;
    cout << p << endl;
}

int getSum(int *arr, int n)
{
    cout << "Size is " << sizeof(arr) << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void swap(char *x, char *y)
{
    char *t = x;
    x = y;
    y = t;
}

int main()
{

    // int arr[10] = {2, 56, 58, 36};
    /*int *divyam = arr;
    // Address of first memory block
    cout<<arr<<endl;
    cout<<*arr<<endl;
    cout<<&arr[0]<<endl;
    // Value stored at first memory block
    cout<<arr[0]<<endl;
    cout<<divyam<<endl;
    cout<<divyam[0]<<endl;
    cout<<*divyam<<endl; */

    // Iska mtlb jo arr[0] pe value hai usme increment hona 1 se
    // cout << *arr + 1 << endl;
    // cout << *(arr) + 1 << endl;
    // Iska mtlb 0th index me 1 jod diya aur ab vo 1st index bn gya , so here we will get value of arr[1]
    // cout << *(arr + 1) << endl;

    // arr[i] = *(arr + i)
    // i[arr] = *(arr + i)

    // for (int i = 0; i < 10; i++)
    // cout << i[arr] << " ";

    // int Dogesh[10] = {1, 2};
    // int *Cheemda = &Dogesh[0];

    // cout<<sizeof(Dogesh)<<endl;
    // cout<<sizeof(*Dogesh)<<endl;
    // cout<<sizeof(&Dogesh)<<endl;
    // cout<<sizeof(Dogesh[0])<<endl;

    // cout<<sizeof(Cheemda)<<endl;
    // cout<<sizeof(*Cheemda)<<endl;
    // cout<<sizeof(&Cheemda)<<endl;
    // cout<<sizeof(Cheemda[0])<<endl;

    // cout<<Cheemda<<endl;
    // cout<<&Cheemda<<endl;
    // cout<<&Cheemda[0]<<endl;
    // cout<<*Cheemda<<endl;

    // int Dogesh[50] = {0};
    // int *Dogelina = &Dogesh[0];
    // cout << Dogelina << endl;
    // Dogelina = Dogelina + 1;
    // cout << Dogelina << endl;

    // int arr[10] = {01, 06, 10, 15, 21, 23, 17, 43, 56, 52};
    // char Divyam[10] = "DIVYAMVJ";

    // char *Dogesh = &Divyam[0];
    // cout << arr << endl;
    // PRINTS AN ENTIRE STRING
    // cout << Dogesh << endl;

    // int a = 7;
    // int Dogesh[5] = {5,4,3,2,1};
    // int *p = &a;
    // cout << p << endl;
    // update(p);
    // Hum yaha array ke kisi ek part ko bhi run kar skte hai jaise yaha humne 3rd iteration se 5th iteration tk sum kiya h
    // cout<<getSum((Dogesh)+2, 3 )<<endl;

    char *x = "geeksquiz";
    char *y = "geeksforgeeks";
    char *t;
    swap(x, y);
    cout << x << " " << y;
    t = x;
    x = y;
    y = t;
    cout << " " << x << " " << y;
    return 0;
}