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

class Human
{
public:
    char name;
    Human()
    {
        this->name = 'B';
    }
};

class Dog : public Animal , public Human
{
public:
    void Sleep()
    {
        cout << "The dog is sleeping" << endl;
    }
};

int main()
{
    Dog RoadWheeler;
    cout<<RoadWheeler.name<<endl;
    return 0;
}