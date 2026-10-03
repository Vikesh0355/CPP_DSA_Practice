/* const_cast
The const_cast operator is used to modify the const or volatile qualifier of a variable.
It allows programmers to temporarily remove the constancy of an object and make modifications.
Caution must be exercised when using const_cast, as modifying a const object can lead to undefined behavior.*/
/*Use case 1: Modifying a const variable: You can use const_cast to remove the const qualifier and modify the variable.*/
#include <iostream>
using namespace std;
int main()
{
    const int a =8;
    int* ptr = const_cast<int*>(&a);
    *ptr =20;
    cout << "Modified number: " << *ptr;
    return 0;
}