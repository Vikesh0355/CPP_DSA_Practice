/*Constructor overloading*/
/*In C++, We can have more than one constructor in a class with same name, as long as each has a different list of arguments.This concept is known as Constructor Overloading*/
#include <iostream>
using namespace std;
class circle
{
    float r;
    public:
    circle() /*Default constructor*/
    {
      r= 5.0;
    }
    circle(float r)  /*Constructor Overloading*/
    {
     this->r = r;   
    }
    void show()
    {
        cout<<"Area ="<<3.14*r*r<<endl;

    }
};


int main() {
circle C1; /*Here the constrcutor Circle will be invoked*/
circle C2(3.5); /*Constructor Overloading*/
C1.show();
C2.show();

return 0;
}

/*  g++ -std=c++14 Constructor_OverLoading.cpp -o Constructor_OverLoading -pthread */
/* ./Constructor_OverLoading  */