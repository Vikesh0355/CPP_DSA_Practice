/* std::nothrow makes new return nullptr instead of throwing std::bad_alloc when memory allocation fails.*/
#include <iostream>
#include<new>
using namespace std;

int main()
{
   int* p = new (std::nothrow) int[1000000000000];
   if(p == nullptr_t)
   {
     cout<<"memory Allocation was failed"<<endl;
   }
   else
   {
     cout<<"Memory allocated successfully"<<endl;
   }
   return 0;
}

/* Remember: std::nothrow is mainly used with new when you want to check for allocation failure using nullptr instead of exceptions */


/* noexcept means the function guarantees that no exception will escape from it. If an exception tries to escape, the program calls std::terminate().*/

#include <iostream>
#include <stdexcept>

void foo() noexcept {
    throw std::runtime_error("Error!");
}

int main() {
    foo();
}