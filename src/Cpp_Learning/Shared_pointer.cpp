/* Shared_ptr allows multiple pointers to share ownership of the same object. It uses references counting to manage memory*/
/* Supports shared ownership */
/* Uses reference counting to manage the object*/
/* make_shared is the recommended way to create a shared_ptr*/

#include <iostream>
#include <memory>
using namespace std;

class Rectangle
{
    int length, breadth;
    public:
    Rectangle(int l, int b):length(l), breadth(b){}
    int area()
    {
        return length*breadth;
    }
};

int main()
{
    shared_ptr<Rectangle> ptr1 = make_shared<Rectangle>(10, 5);
    shared_ptr<Rectangle> ptr2 = ptr1;
    cout<<ptr1->area()<<endl;
    cout<<ptr2->area()<<endl;
    cout<<ptr1.use_count();
    return 0;

}

/* Explanation: make_shared() creates a shared_ptr, and copying ptr1 to ptr2 makes them share ownership.
use_count() shows the number of owners, and the object is destroyed when the last shared_ptr is gone. */