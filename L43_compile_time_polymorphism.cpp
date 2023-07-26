#include <iostream>
using namespace std;

// FUNCTION OVERLOADING
class A
{
public:
    void SayHello()
    {
        cout << "Hello world" << endl;
    }

    int SayHello(int s)
    {
        cout << "Hello world" << endl;
        return 0;
    }
};

// OPERATOR OVERLOADING
class B
{
public:
    int a, b;

public:
    int add()
    {
        return this->a + this->b;
    }

    void operator+(B obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "output : " << abs(value2 - value1) << endl;
    }

    void operator*(B obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "output : " << (value1 % value2) << endl;
    }

    void operator()()
    {
        cout << "Mera kaam to kuch aur tha par mujhe overload kr diya " << this->a << endl;
    }
};

int main()
{
    B b1, b2;
    b1.a = 10;
    b2.a = 14;
    b1 + b2;
    b1 *b2;
    b1();
    return 0;
}