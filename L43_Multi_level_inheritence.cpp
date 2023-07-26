#include<iostream>
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

class Vodafone_Wala_Kutta : public Dog
{
    public:
    void eating()
    {
        cout<<"The kutta is eating"<<endl;
    }
};

int main()
{
    Vodafone_Wala_Kutta pitBUll;
    pitBUll.eating();
    cout<<pitBUll.age<<endl;
    return 0;
}