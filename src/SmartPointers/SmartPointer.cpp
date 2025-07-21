Smart pointers in C++ are wrappers around raw pointers, providing automatic memory management and improving the safety of your code. 
They help you avoid common problems like memory leaks, dangling pointers, and double frees, which are common issues when using raw pointers.

In C++11 and beyond, the Standard Library provides three types of smart pointers:

std::unique_ptr: A smart pointer that owns a dynamically allocated object exclusively. It is non-copyable but can be moved.

std::shared_ptr: A smart pointer that can be shared among multiple owners. The object is destroyed only when the last shared_ptr goes out of scope.

std::weak_ptr: A smart pointer that provides a non-owning "weak" reference to an object managed by shared_ptr. It helps prevent circular references in shared_ptr.

/*Example unique_ptr*/
#include <iostream>
#include <memory>  // For std::unique_ptr

int main() {
    // Create a unique pointer to an integer
    std::unique_ptr<int> ptr = std::make_unique<int>(10);

    std::cout << "Value: " << *ptr << std::endl;

    // Unique pointers cannot be copied, but can be moved
    std::unique_ptr<int> ptr2 = std::move(ptr);  // Move ownership
    // ptr is now nullptr
    if (!ptr) {
        std::cout << "ptr is now nullptr." << std::endl;
    }

    std::cout << "Value in ptr2: " << *ptr2 << std::endl;
    return 0;  // No need to delete manually
}

/*Example:shared ptr*/
#include <iostream>
#include <memory>  // For std::shared_ptr

int main() {
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
#include <memory>  // For std::shared_ptr, std::weak_ptr

int main()
 {
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);

    // Create a weak pointer to the same object
    std::weak_ptr<int> weakPtr = sharedPtr;

    // Convert weak_ptr to shared_ptr
    std::shared_ptr<int> lockedPtr = weakPtr.lock();
    if (lockedPtr) {
        std::cout << "Weak pointer is locked: " << *lockedPtr << std::endl;
    } else {
        std::cout << "Weak pointer is expired." << std::endl;
    }

    // Release shared_ptr, making the object go out of scope
    sharedPtr.reset();

    // Try to lock weak_ptr again
    lockedPtr = weakPtr.lock();
    if (lockedPtr) {
        std::cout << "Weak pointer is locked: " << *lockedPtr << std::endl;
    } else {
        std::cout << "Weak pointer is expired." << std::endl;
    }

    return 0;
}
