#include <iostream>
using namespace std;

void update(int **p2)
{
    // p2 = p2 + 1;     // No change
    // *p2 = *p2 + 1;   // change
    **p2 = **p2 + 1; // change
}

int main()
{
    int a = 5;
    int *ptr = &a;
    int **ptr1 = &ptr;

    /*
    cout<<"Printing ptr : "<<ptr<<endl;
    cout<<"Printing value of ptr : "<<*ptr<<endl;
    cout<<"Printing address of ptr : "<<&ptr<<endl;
    cout<<"Printing address of ptr: "<<ptr1<<endl;
    cout<<"Printing value of ptr : "<<*ptr1<<endl;
    cout<<"Printing value of ptr : "<<&ptr1<<endl;
    cout<<a<<endl;
    cout<<*ptr<<endl;
    cout<<**ptr1<<endl;
    cout<<"Address of a is : "<<&a<<endl;
    cout<<"Address of a is : "<<ptr<<endl;
    cout<<"Address of a is : "<<*ptr1<<endl;
    */

    cout << "Before " << a << endl;
    cout << "Before " << ptr << endl;
    cout << "Before " << ptr1 << endl;
    update(ptr1);
    cout << "After " << a << endl;
    cout << "After " << ptr << endl;
    cout << "After " << ptr1 << endl;

    return 0;
}