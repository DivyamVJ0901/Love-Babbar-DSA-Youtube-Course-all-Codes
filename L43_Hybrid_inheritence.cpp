#include <iostream>
using namespace std;

class A
{
public:
    void func1()
    {
        cout << "We are in function 1" << endl;
    }
};

class B : public A
{
public:
    void func2()
    {
        cout << "We are in function 2" << endl;
    }
};

class D
{
public:
    void func4()
    {
        cout << "We are in function 4" << endl;
    }
};

class C : public D, public B
{
public:
    void func3()
    {
        cout << "We are in function 3" << endl;
    }
};

int main()
{
    C obj;
    obj.func1();
    obj.func2();
    obj.func3();
    obj.func4();

    return 0;
}