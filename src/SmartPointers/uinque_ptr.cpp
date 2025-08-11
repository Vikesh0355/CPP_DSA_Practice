#include<iostream>
#include<cstring>
using namespace std;

class Base
{
    public:
    Base()
    {
        cout<<"Base class Constructor is called\n";
    }
    ~Base()
    {
        cout<<"Base class Destructor is called\n";
    }
};

int main()
{
    std::unique_ptr<Base> unptr  = std::make_unique<Base>();
    system("pause>null");

}