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

class C : public A
{
public:
    void func3()
    {
        cout << "We are in function 3" << endl;
    }
};

int main()
{
    A var1;
    var1.func1();
    B var2;
    var2.func1();
    var2.func2();
    C var3;
    var3.func1();
    var3.func3();
    return 0;
}