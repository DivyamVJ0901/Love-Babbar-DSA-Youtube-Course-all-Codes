#include <iostream>
using namespace std;

class Animal
{
public:
    int age;
    int weight;

    Animal()
    {
        this->age = 12;
        this->weight = 45;
    }
};

class Dog : public Animal
{
    public:
    void Sleep()
    {
        cout << "The dog is sleeping" << endl;
    }
};

int main()
{
    Dog Cherry;
    cout<<Cherry.age<<endl;
    cout<<Cherry.weight<<endl;
    Cherry.Sleep();
    return 0;
}