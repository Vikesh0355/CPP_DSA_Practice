/*Const_cast in c++*/
/*Note: */
/*The expression const_cast<t> can be used to change the const or volatile qualifier of type pointer or reference*/
/*Where T must be a pointer, reference, or pointer-to-member type*/

/*1. When the actual referred object/variable is not constant*/

#include <iostream>
#include <cstring>

void printLength(char* str) 
{
    std::cout << "Length: " << strlen(str) << std::endl;
}

int main() {
    const char* message = "Hello";

    // printLength(message); // ❌ Error: cannot convert const char* to char*

    // ✅ Use const_cast to remove constness
    printLength(const_cast<char*>(message));

    return 0;
}


#ifdef CONST_CAST_1
/*2. When we need to call some 3rd party library where it is taking variable/object as non const but not changing that*/

void thirdPartyLibrary(int* x)
{
	int k =10;
	cout<<k+*(x);
}

int main()
{
	const int x=20;
	const int *px = &x;
	thirdPartyLibrary(const_cast<int*>(px));
	
}
#endif

/*  g++ -std=c++14 const_cast.cpp -o const_cast -pthread */
/* ./const_cast  */