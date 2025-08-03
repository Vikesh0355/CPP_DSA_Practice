Smart pointers in C++ are wrappers around raw pointers, providing automatic memory management and improving the safety of your code. 
They help you avoid common problems like memory leaks, dangling pointers, and double frees, which are common issues when using raw pointers.

In C++11 and beyond, the Standard Library provides three types of smart pointers:

std::unique_ptr: A smart pointer that owns a dynamically allocated object exclusively. It is non-copyable but can be moved.

std::shared_ptr: A smart pointer that can be shared among multiple owners. The object is destroyed only when the last shared_ptr goes out of scope.

std::weak_ptr: A smart pointer that is used to break circular references in shared_ptrs. It does not contribute to the reference count and does not prevent memory from being freed.

/*Example unique_ptr*/
#include <iostream>
#include <memory>  // For std::unique_ptr

int main()
{
    // Create a unique pointer to an integer
    std::unique_ptr<int> ptr = std::make_unique<int>(10);

    std::cout << "Value: " << *ptr << std::endl;

    // Unique pointers cannot be copied, but can be moved
    std::unique_ptr<int> ptr2 = std::move(ptr);  // Move ownership
    // ptr is now nullptr
    if (!ptr) 
    {
        std::cout << "ptr is now nullptr." << std::endl;
    }

    std::cout << "Value in ptr2: " << *ptr2 << std::endl;
    return 0;  // No need to delete manually
}

/*Example:shared ptr*/
#include <iostream>
#include <memory>  // For std::shared_ptr

int main()
{
    // Create a shared pointer
    std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
    
    std::cout << "ptr1 value: " << *ptr1 << std::endl;
    
    // Shared ownership: create another shared pointer to the same object
    std::shared_ptr<int> ptr2 = ptr1;  // ptr2 shares ownership with ptr1
    
    std::cout << "ptr2 value: " << *ptr2 << std::endl;
    std::cout << "Shared count: " << ptr1.use_count() << std::endl;  // Prints 2
    
    return 0;  // Memory will be freed when ptr1 and ptr2 go out of scope
}

/*std::weak_ptr*/
#include <iostream>
#include <memory>  // For weak_ptr and shared_ptr

void weakPointerExample() 
{
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(200);
    std::weak_ptr<int> weakPtr = sharedPtr;  // Create a weak_ptr from shared_ptr
    
    std::cout << "Use count before: " << sharedPtr.use_count() << std::endl;
    
    // Lock weak_ptr to obtain a shared_ptr
    if (auto lockedPtr = weakPtr.lock()) 
    {
        std::cout << "Value from weak_ptr: " << *lockedPtr << std::endl;
    } 
    else
    {
        std::cout << "Resource no longer available" << std::endl;
    }

    sharedPtr.reset();  // Reset the shared_ptr, which destroys the resource
    
    std::cout << "Use count after: " << sharedPtr.use_count() << std::endl;
    
    // Trying to lock again after resource is destroyed
    if (auto lockedPtr = weakPtr.lock())
    {
        std::cout << "Value from weak_ptr: " << *lockedPtr << std::endl;
    } 
    else 
    {
        std::cout << "Resource no longer available" << std::endl;  // Will be printed
    }
}

int main() 
{
    weakPointerExample();
    return 0;
}

