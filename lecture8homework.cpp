//  QUES - 1) WAP to print nth (n entered by the user) term of an AP whose general term is given.
//  QUES - 2) WAP to print 1 set bits in a and b.
//  QUES - 3) WAP to print Fibonacci series.

// QUES - 1)
// #include <iostream>
// using namespace std;


// int main()
// {
//     int a , n;
//     cout<<"Enter the value of n : " << endl;
//     cin>>n;
//     a = 3*n + 7;

//     cout<<"The "<<n<<"th term of the series is "<<a<<endl;

//     return 0;
// }

// QUES - 3)
// #include<iostream>
// using namespace std;

// int FabSeries(int n){
//     if(n==1 || n==0){
//         return n;
//     }

//     return FabSeries(n-1) + FabSeries(n-2);
// }

// int main(){
//     int n ;
//     cout<<"Enter the value of n :"<<endl;
//     cin>>n;

//     int z = FabSeries(n);
//     for (int i = 0; i <= n; i++)
//     {
//         cout<<" "<<FabSeries(i);
//     }
//     cout<<endl;
//     cout<<"The "<<n<<"th term is : "<<FabSeries(n-1)<<endl;

    
//     return 0;
// }


// #include<iostream>
// using namespace std;

// void update(int a){
//     a=a/2;
// }

// int main(){
//     int a = 10;
//     update(a);
//     cout<<a<<endl;
//     return 0;
// }


// #include<iostream>
// using namespace std;

// int update(int a){
//     int ans = a*a;
//     return ans;
// }

// int main(){
//     int a = 14;
//     a=update(a);
//     cout<<a<<endl;
//     return 0;
// }