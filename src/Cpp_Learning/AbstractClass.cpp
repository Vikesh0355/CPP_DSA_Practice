/*Pure virtual fuction and ´Abstract base class **/
/*A pure virtual function is a virtual function that has no implementation in the base class and must be overridden by a derived class.*/
/*A class which containe pure virtual function is known as abstract base class */
/**/

#include <iostream>
using namespace std;

class shape
{
    protected:
    float d1, d2;
    public:
    void getdim()
    {
        cin>>d1>>d2;
    }
    virtual float area() = 0;
};
class triangle: public shape
{
    public:
    float area() override
    {
        return 0.5*d1*d2;
    }
};

class rectangle: public shape
{
    public:
    float area() override
    {
        return d1*d2;
    }
    
};

int main()
{
    triangle t;
    cout<<"Enter the triangle base and height"<<endl;
    t.getdim();
    cout<<"Triangle are is: "<<t.area()<<endl;
    
    rectangle r;
    cout<<"Enter the rectangle base and height"<<endl;
    r.getdim();
    cout<<"rectangle are is: "<<r.area()<<endl;
    return 0;
}