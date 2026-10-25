/* weak_ptr is non-owning smart pointer used with shared_ptr. It provides access to an object without increasing it's  reference count. it mainly used to prevent circular ownership between shared_ptr objects */
 /* Doesn't own the manage objects*/
 /* Doesn't increase the shared_ptr reference count*/
 /* Help to  prevent circular ownership*/
 /* Uses lock() to obtain temporary shared_ptr when the object is still alive*/

 #include <iostream>
 #include <memory>
 using namespace std;
 class Rectangle
 {
  int length, breadth;
  public:
  Rectangle(int l, int b): length(l), breadth(b){}
  int area()
  {
    return length*breadth;
  }

 };

 int main()
 {
    shared_ptr<Rectangle> ptr1 = make_shared<Rectangle>(10, 5);
    weak_ptr<Rectangle> ptr2 = ptr1;
    cout<<ptr1->area()<<endl;
    cout<<ptr2.use_count();
    return 0;
 }

 Explanation: ptr1 owns the Rectangle object, while ptr2 observes it without increasing the reference count. lock() can be used to obtain a shared_ptr if the object is still alive.

 #include <iostream>
#include <memory> 
using namespace std;

void WeakPointerExample()
{
    shared_ptr<int>SharedPtr = make_shared<int>(200);
    weak_ptr <int>weakPtr = SharedPtr;
    cout<<"use count before : "<<SharedPtr.use_count()<<endl;
    
    // Lock the weak pointer to obtain a shared pointer
    if(auto lockedptr = weakPtr.lock())
    {
        cout<<"value from weak pointer: "<<*lockedptr<<endl;
    }
    else
    {
        cout<<"Resource no longer available"<<endl;
    }
    SharedPtr.reset(); // reset the shared pointer which destroy the resource
    cout<<"Use count after: "<<SharedPtr.use_count()<<endl;


    if(auto lockedptr = weakPtr.lock())    // Trying to lock again after resource is destroyed
    {
        cout<<"value from weak pointer"<<*lockedptr<<endl;
    }
    else
    {
        cout<<"Resource no longer available"<<endl;
    }

};

int main()
{
   WeakPointerExample();
   return 0;
}
    