/* In C++, a class is a user-defined data type that allows you to group variables and functions into a single unit. 
 It serves as a blueprint for creating objects, which are instances of that class.*/
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    void startEngine() {
        cout << "Engine started for " << brand << endl;
    }
};

int main() {
    Car myCar;
    myCar.brand = "Toyota";
    myCar.year = 2020;
    myCar.startEngine();
    return 0;
}

/* g++ -std=c++20 class.cpp -o class -pthread */

/* ./class  */