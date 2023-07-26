#include<iostream>
using namespace std;

int main(){

    cout<<"This is a simple calculator with some basic operations. "<<endl;
    cout<<"Enter + for addition."<<endl;
    cout<<"Enter - for subtraction."<<endl;
    cout<<"Enter * for multiplication."<<endl;
    cout<<"Enter / for division."<<endl;
    cout<<"Enter % for percentage."<<endl;
    int a , b;

    cout<<"Enter the value of a :"<<endl;
    cin>>a;

    cout<<"Enter the value of b :"<<endl;
    cin>>b;

    char operation;
    cout<<"Enter the operation symbol : "<<endl;
    cin>>operation;

    switch (operation)
    {
    case '+':
        cout<<"The sum of two enterd numbers is "<<a+b<<endl;
        break;

    case '-':
        cout<<"The diffrence of two enterd numbers is "<<a-b<<endl;
        break;

    case '*':
        cout<<"The product of two enterd numbers is "<<a*b<<endl;
        break;

    case '/':
        cout<<"The division of two enterd numbers is "<<a/b<<endl;
        break;

    case '%':
        cout<<"The percentage of two enterd numbers is "<<a%b<<endl;
        break;

    default:
        cout<<"Pls enter a valid Input.!!"<<endl;
        break;
    }
    return 0;
}