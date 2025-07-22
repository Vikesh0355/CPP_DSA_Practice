/*Copy Constructor: A copy constructor is a type of constructor that initializes an object using another object of the same class.*/

#include <iostream>
using namespace std;
class sample
{
    int a, b;
    public:
    sample(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    sample(sample &old) /*Copy constructor*/
    {
        a = old.a;
        b = old.b;
    }
    void print()
    {
      cout<<"a = "<<a<<endl;
      cout<<"b = "<<b<<endl; 
    }

};

int main() {
sample s1(10, 20);
sample s2(s1); /*Calling copy constructor*/
s1.print();
s2.print();

    return 0;
}