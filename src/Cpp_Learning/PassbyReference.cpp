#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int main()
{
    int x = 5;
    int y = 10;

    cout << "Before swap value of x = "<< x << "\ty = "<< y << endl;

    swap(x, y);

    cout << "After swap value of x = "<< x << "\ty = "<< y << endl;

    return 0;
}