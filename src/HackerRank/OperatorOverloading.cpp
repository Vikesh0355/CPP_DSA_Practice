#include <iostream>
using namespace std;

class ComplexNum
{
    private:
    double real, imag;
    public:
    ComplexNum(double r = 0, double i = 0):real(r), imag(i) {}
    /*Overloading the + operator*/
    ComplexNum operator+(const ComplexNum& other) const
    {
        return ComplexNum(real + other.real, imag + other.imag);

    }
    void dispaly() const{
        cout<<real<<" + " <<imag<<"i"<<endl;
    }

};

int main()
{
    ComplexNum c1(3.0, 4.0);
    ComplexNum c2(1.0, 2.0);
    ComplexNum c3 = c1 + c2;
    c3.dispaly();
    return 0;
}

/*  g++ -std=c++14 OperatorOverloading.cpp -o OperatorOverloading -pthread */
/* ./OperatorOverloading  */