#include <iostream>
using namespace std;

/*Scope resolution Operator*/

/*1. *To access a global variable when there is a local variable with same name:*/
/*2. *To define the function outside of the class*/
/*3. *To access a class’s static variables.*/
int a =100;
class Vikesh
{
    int a;
    static int x;
    public:
    void get(int x);
    void show();

};

void Vikesh::get(int x)
{
    //int a;
    cout<<"Enter the value of a"<<endl;
    cin>>a;

    
}
void Vikesh::show()
{ 
    cout<<"Value of global a="<<::a<<endl; /*Aceesing gloabla variable*/
    cout<<"Value of local a="<<a<<endl;
    cout<<"value of local x="<<x<<endl;
    cout<<"Value of static x is "<<Vikesh::x<<endl;
    
}
int Vikesh::x=100;

int main()
{
    Vikesh V;
    V.get(2);
    V.show();
    
    return 0;
}

/*  g++ -std=c++14 ScopeResolutionOperator.cpp -o ScopeResolutionOperator -pthread */
/* ./ScopeResolutionOperator  */