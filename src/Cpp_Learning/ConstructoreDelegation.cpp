/*Constructor delegation: Calling a constructor inside another constructor*/
#include <iostream>
using namespace std;

class A
{
    int x, y,z;
    public:
    A() /* Default constructor A */
    {
      x = 0;
      y = 0;
      z = 0;
    }
    A(int y, int z):A() /*constructor delegation */
    {
        this->y = y;
        this->z = z;
    }
    void show()
    {
        cout<<"x  = "<<x<<"\t y = "<<y<<"\t z = "<<z<<endl;
    }
};

int main()
{
    A obj(3, 5);
    obj.show();
    return 0;
}