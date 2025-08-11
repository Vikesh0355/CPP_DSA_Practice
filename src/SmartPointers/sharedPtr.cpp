/*Example:shared ptr*/
#include <iostream>
#include <memory>  // For std::shared_ptr
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
    
    std::shared_ptr<Base> shptr1  = std::make_shared<Base>();
    cout<<"Shared_ptr count:"<<shptr1.use_count()<<endl;
    {
        std::shared_ptr<Base> shptr2  = shptr1;
        cout<<"Shared_ptr count:"<<shptr1.use_count()<<endl;

    }

    system("pause>null");

}

