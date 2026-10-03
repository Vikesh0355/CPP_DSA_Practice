#include <iostream>
using namespace std;
/* 1. it performs implicit conversion between types*/
#include <iostream>
using namespace std;

int main()
{
    float f = 6.5;
    int v = f;
    cout<<"After implicit conversion value of v is: "<<v<<endl;
    v = static_cast<int>(f);
    cout<<"After static_cast conversion value of v is: "<<v<<endl;;
    return 0;
}

/* 2. static cast is more restrictive than c -style cast
//Example: char* to int* is allowed in c style  but not with static_cast */	

#include <iostream> 
using namespace std; 
int main()
{
	char c;            /*1 byte*/
	int *p = (int*)&c; /*4 byte*/
	*p=5;              /*PASS at compile-time but FAIL at run time.(that's why it is dangerous)*/
	//int* ip = static_cast<int>(&c); /*FAIL*/ /*compile time error, because not compatible pointer type*/
	return 0;
}

/* 3. Static_cast avoid cast from derived to private base pointer */

#include <iostream>
using namespace std;
class Base{};
class Derived: private Base{};
int main()
{
    Derived d1;
    Base *bp1  = (Base *)&d1; // allowed
    Base *bp2 = static_cast<Base*>(&d1); // not allowed

}

/* 4. Use for all upcast, but never use for confused down cast. */

#include <iostream> 
using namespace std; 
class Base{ };
class Derived1:public Base{};
class Derived2:public Base{};
int main()
{
    Derived1 d1;
    Derived2 d2;
    Base *bp1 = static_cast<Base*>(&d1);
    Base *bp2 = static_cast<Base*>(&d2);
    Derived1 *d1p = static_cast<Derived1*>(&bp1); /*Not allowed */
    Derived1 *d2p = static_cast<Derived2*>(&bp2); /*Not allowed */
    return 0;
}

/*5. static_cast should be preferred when converting to void* OR from void* */

#include <iostream> 
using namespace std; 
int main()
{	
 int a =100;
 void *p = static_cast<void*>(&a);
 int *ptr = static_cast<int*>(p);
 cout<<*ptr;
 return 0;
}  