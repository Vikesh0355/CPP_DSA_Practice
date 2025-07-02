/* 2. Use static_cast when conversion between types is provided through conversion operator or conversion constructor*/
#include <iostream>
using namespace std;

class Celsius {
public:
    double temperature;

    // Conversion constructor: Fahrenheit to Celsius
    Celsius(double fahrenheit) {
        temperature = (fahrenheit - 32) * 5.0 / 9.0;
    }

    void display() {
        std::cout << "Temperature in Celsius: " << temperature << "°C\n";
    }
};

int main() {
    double fahrenheit = 98.6;

    // Use static_cast to convert double to Celsius using the conversion constructor
    Celsius celsiusTemp = static_cast<Celsius>(fahrenheit);
    celsiusTemp.display();

    return 0;
}

/*3. static cast is more restrictive than c -style cast */
/*Example: char* to int* is allowed in c style  but not with static_cast */	
#ifdef STATIC_CAST_1
int main()
{
	char c;            /*1 byte*/
	int *p = (int*)&c; /*4 byte*/
	*p=5;              /*PASS at compile-time but FAIL at run time.(that's why it is dangerous)*/
	//int* ip = static_cast<int>(&c); /*FAIL*/ /*compile time error, because not compatible pointer type*/
	return 0;
}
#endif

/*4. Static_cast avoid cast from derived to private base pointer */
#ifdef STATIC_CAST_2
class Base{};

class Derived:private Base{};


int main()
{
	Derived d1;
	Base *bp1= (Base*)&d1;  /*Allowed*/
	Base *bp2= static_cast<Base*>(&d1); /*Not Allowed*/
}
#endif

/*5. static_cast should be preferred when converting to void* OR from void*/
#ifdef STATIC_CAST_3
int main()
{
	
	int i = 10;
	void *v = static_cast<void*>(&i);
	int *ip = static_cast<int*>(v);
	return 0;
}  
#endif

/* 6. Use for all upcast, but never use for confused down cast. */
#ifdef STATIC_CAST_4
class Base{ };
class Derived1:public Base{};
class Derived2:public Base{};
int main()
{
    Derived1 d1;
    Derived2 d2;
    Base *bp1 = static_cast<Base*>(&d1);
    Base *bp2 = static_cast<Base*>(&d2);
    Derived1 *d1p = static_cast<Derived1*>(&bp1); /*Not allowed*/
    Derived1 *d2p = static_cast<Derived2*>(&bp2); /*Not allowed*/
    
    return 0;
}
#endif


/*  g++ -std=c++14 Static_cast2.cpp -o Static_cast2 -pthread */
/* ./Static_cast2  */