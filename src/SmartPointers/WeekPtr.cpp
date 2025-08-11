#include<iostream>
#include<memory>  // For shared_ptr, weak_ptr
using namespace std;

class myClass
{
public:
    myClass()
    {
        cout << "Constructor invoked" << endl;
    }
    ~myClass()
    {
        cout << "Destructor invoked" << endl;
    }
};

int main()
{
    weak_ptr<myClass> wePtr1;  // Declare weak_ptr to observe myClass objects

    {
        // Create a shared_ptr to manage myClass object
        shared_ptr<myClass> shptr1 = make_shared<myClass>();  // Constructor invoked

        // Assign shared_ptr to weak_ptr
        wePtr1 = shptr1;
        
        // We can access the object via weak_ptr if needed (using lock())
        if (auto locked = wePtr1.lock()) {
            cout << "Object is still alive!" << endl;
        } else {
            cout << "Object is no longer alive!" << endl;
        }
    }
    
    // After the block, the shared_ptr goes out of scope and the object is destroyed.
    // Destructor will be invoked at this point

    // We can check if the object is still alive through the weak_ptr
    if (auto locked = wePtr1.lock()) {
        cout << "Object is still alive!" << endl;
    } else {
        cout << "Object is no longer alive!" << endl;  // This will be printed
    }

    return 0;
}
