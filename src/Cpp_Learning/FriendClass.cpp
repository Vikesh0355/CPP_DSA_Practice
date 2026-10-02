#include <iostream>
using namespace std;

class Vikesh
{
    private:
    int private_variable;
    protected:
    int protected_variable;
    public:
    Vikesh()
    {
       private_variable = 10;
       protected_variable = 20;
    }
    friend class Abhishek;
    
};
// Here, class Abhishek is declared as a
// friend inside class Vikesh. Therefore,
// Abhishek is a friend of class Vikesh. Class Abhishek
// can access the private members of
// class Vikesh.
class Abhishek
{
    public:
    void display(Vikesh &t)
    {
       cout << "The value of Private Variable = " << t.private_variable << endl;    
       cout << "The value of Protected Variable = "  << t.protected_variable;         
    }
    
};

int main()
{
    Vikesh V ;
    Abhishek Abh;
    Abh.display(V);
    return 0;
}