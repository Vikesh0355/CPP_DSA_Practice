/* Smart pointers are objects that manage dynamically allocated memory automatically. They are provided by c++ STL and helps to manage the lifetime of dynamically allocated objects*/
/* Automatically release memory when the managed object is no longer needed*/
/* Help reduce memory leak and dangling pointer issue */
/* The <memory> header provides smart pointers such as unique_ptr, shared_ptr, weak_ptr*/

/* Syntax of Smart Pointers*/
smart_pointer_type<data_type>pointer_name;

E.g unique_ptr <int> ptr;
    shared_ptr <int> ptr;
    Weak_ptr<int> ptr;

1. unique_ptr : unique_ptr stores one pointer only at a time. We can not copy unique_ptr, only transfer ownership of object to another unique_ptr using the move() method.
. Only one unique_ptr can own an object at a time.
. Lightweight and efficient
. ideal for single ownership scenarios.
. make_unique() is the recommended and safer way to create a unique_ptr.

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
    unique_ptr<Rectangle> ptr1 = make_unique<Rectangle>(10, 6);
    cout<<ptr1->area()<<endl;
    unique_ptr<Rectangle>ptr2 = std:: move(ptr1);
    cout<<ptr2->area();
    return 0;

}

/* Explanation: make_unique() creates a unique_ptr that exclusively owns the Rectangle object,
while move() transfers ownership from ptr1 to ptr2. The object is automatically deleted when the owning unique_ptr goes out of scope. */