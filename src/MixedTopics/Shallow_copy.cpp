/*A shallow copy creates a new object, but instead of copying the actual data, it copies references to the data. This means that both the original and the copied object share the same memory locations for the referenced data.**/
/*shallow copy is done through copy constructor or copy assignment operator*/

#include <iostream>
using namespace std;

class Dummy {
    private:
    int a, b;

    public:
    // Default constructor
    Dummy() : a(0), b(0) {}

    void SetData(int x, int y) {
        a = x;
        b = y;
    }

    void ShowData() const {
        cout << "\na = " << a << " b = " << b << endl;
    }

    // Copy constructor with const reference and initialization list
    Dummy(const Dummy& d) : a(d.a), b(d.b) {}

    ~Dummy() {
        // Destructor can be left empty if no special cleanup is needed
    }
};

int main() {
    Dummy d1;
    d1.SetData(1, 2);
    Dummy d2(d1);
    d1.ShowData();
    d2.ShowData();
    return 0;
}

/*  g++ -std=c++14 Shallow_copy.cpp -o Shallow_copy -pthread */
/* ./Shallow_copy  */