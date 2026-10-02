/*Lambda Expression: Lambda expression allows us to define anonymous function objects which can either be used inline or passed as an argument.*/

/*
auto greet = []() {
  // lambda function body
};
Here,

[] is called the lambda introducer which denotes the start of the lambda expression
() is called the parameter list which is similar to the () operator of a normal function */

#include <iostream>
using namespace std;

int main()
{
    /*lambda function that takes two integer parameters and display their sum*/
    auto add = [](int a, int b)
    {
        cout<<"sum = "<<a+b<<endl;
    };
    /* call the lambda function*/
    add(100, 20);
    return 0;
}