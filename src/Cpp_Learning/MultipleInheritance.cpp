/* The Diamond problem in c++ occurs in multiple inheritance when a class inherits from two classes that both inherits from  the same base class*/
/*      A
       / \
      B   C
       \ /
        D   */
#include <iostream>
using namespace std;

class A
{
public:
    void show()
    {
        cout << "Hello from A" << endl;
    }
};

class B : public A
{
};

class C : public A
{
};

class D : public B, public C
{
};

int main()
{
    D obj;

    obj.show();  // ❌ Error: Ambiguous
}


/* How do we solve this?*/
/* We use virtual inheritance. */

#include <iostream>
using namespace std;

class A
{
public:
    void show()
    {
        cout << "Hello from A" << endl;
    }
};

class B : virtual public A
{   public:
    void show()
    {
        cout << "Hello from B" << endl;
    }
};

class C : virtual public A
{   public:
    void show()
    {
        cout << "Hello from C" << endl;
    }
};

class D : public B, public C
{
    public:
    void show()
    {
        cout << "Hello from D" << endl;
        B::show(); // TO call specific show function from class b
    }
};

int main()
{
    D obj;

    obj.show();  // ✅ No ambiguity

    return 0;
}