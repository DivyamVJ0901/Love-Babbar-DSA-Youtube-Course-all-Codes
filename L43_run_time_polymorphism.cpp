#include <iostream>
using namespace std;

class Animal
{
public:
    void Sleep()
    {
        cout << "The ANIMAL is sleeping" << endl;
    }
};

class Dog : public Animal
{
public:
    void Sleep()
    {
        cout << "The DOG is sleeping" << endl;
    }
};

int main()
{
    Dog cheem;
    cheem.Sleep();
    // B b1, b2;
    // b1.a = 10;
    // b2.a = 14;
    // b1 + b2;
    // b1 *b2;
    // b1();
    return 0;
}