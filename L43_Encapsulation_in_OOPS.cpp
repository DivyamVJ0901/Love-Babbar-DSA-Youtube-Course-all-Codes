#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int age;
    int height;

public:
    int getAge(){
        return this->age;
    }

    int setHeight(int h){
        this->height = h;
    }
};


int main()
{

    return 0;
}