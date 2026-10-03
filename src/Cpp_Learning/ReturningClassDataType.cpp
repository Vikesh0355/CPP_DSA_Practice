#include <iostream>
using namespace std;

/* Returning class data type */

class Test
{
    int a, b;
    public:
    void getdata();
    void display();
    Test sum(Test);  
};

void Test::getdata()
{
    cout<<"Enter the value of a and b"<<endl;
    cin>>a>>b;
}

void Test::display()
{
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
   
}

Test Test::sum(Test t2)
{
  Test t3;
  t3.a = a + t2.a;
  t3.b = b + t2.b;
  return t3;
}

int main()
{
    Test t1, t2, t3;
    t1.getdata();
    t2.getdata();
    t3 = t1.sum(t2);
    t3.display();
    return 0;
}