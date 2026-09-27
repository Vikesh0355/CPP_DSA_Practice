/* get the size of an array*/

#include <iostream>
using namespace std;

int main()
{
    int array[5] = {10, 20, 30, 40, 50};
    cout <<sizeof(array)<<endl; 
    return 0;
}

/* You learned from the Data Types chapter that an int type is usually 4 bytes, so from the example above, 4 x 5 (4 bytes x 5 elements) = 20 bytes.*/

/* To find out how many elements an array has, you have to divide the size of the array by the size of the first elements in the array */

#include <iostream>
using namespace std;

int main()
{
    int array[5] = {10, 20, 30, 40, 50};
    cout <<sizeof(array)/sizeof(array[0])<<endl; 
    return 0;
}