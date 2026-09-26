/**A manipulator is a special function in C++ that is used with input/output streams (like cin, cout ) to change the way data is shown or read. We can use manipulators when we want to :

    Format numbers
    Set precision (decimals)
    Align text
    Change number base (like decimal to hexadecimal)
    Control spacing
 ********************************/
 
#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    
    bool value = true;

    // Output a new line and flush the stream
    cout << "Hello" << endl;

    // Set width to 10 for the next output
    cout << setw(10) << 42 << endl;

    // Set precision to 3 for floating-point numbers
    cout << setprecision(3) << 3.14159 << endl;

    // Use fixed-point notation
    cout << fixed << 3.14159 << endl;

    // Use scientific notation
    cout << scientific << 3.14159 << endl;

    // Show the decimal point even for whole numbers
    cout << showpoint << 42.0<<endl;

    // Display boolean as true/false
    cout << boolalpha << value << endl;

    // Display boolean as 1/0
    cout << noboolalpha << value<<endl;

    return 0;
}

/*  g++ -std=c++14 Manipulator.cpp -o Manipulator -pthread */
/* ./Manipulator  */