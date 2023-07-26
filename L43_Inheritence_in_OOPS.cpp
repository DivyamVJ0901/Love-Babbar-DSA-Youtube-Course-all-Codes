#include <iostream>
using namespace std;

class Human
{
public:
    int Height;
    int age;
    int Weight;

public:
    int getHeight()
    {
        return this->Height;
    }
    int setHeight(int h)
    {
        this->Height = h;
    }
};

class Male : public Human
{
public:
    string color;
    void work()
    { 
        cout << "I am doing coding right now" << endl;
    }
};

int main()
{
    Male me;
    me.setHeight(171);
    cout << me.getHeight() << " cms" << endl;
    me.work();
    cout << "The weight of male is : " << me.Weight << endl;

    return 0;
}