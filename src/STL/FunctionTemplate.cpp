#include<iostream>
using namespace std;

template<typename T>
T add(T a, T b)  // template function for homogenious data type
{
    return a+b;
}

template<typename T1, typename T2> // template function for hetrogenious dta type
auto sub(T1 a, T2 b) {
    return a - b;
}

int main()
{
    cout<<add(1, 3)<<endl;
    cout<<add(3.14, 4.5)<<endl;
    cout<<sub(5,4)<<endl;
    cout<<sub(3.5,1)<<endl;
    return 0;
}