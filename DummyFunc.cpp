#include<iostream>
using namespace std;

int dummy(int n){
    n++;
    cout<<"The value of n is (in non-main function) : "<<n<<endl;
}

int main(){
    int n;
    cout<<"Enter the value of n : "<<endl;
    cin>>n;

    cout<<"The value of n is : "<<n<<endl;
    cout<<dummy(n)<<endl;
    return 0;
}