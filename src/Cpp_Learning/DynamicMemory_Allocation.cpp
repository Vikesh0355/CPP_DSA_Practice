/***********************************************
Dynamic Memory Allocation:
Dynamic memory allocation gives programmers the ability to:

a. Allocate memory at runtime on the Heap.
b. Non-static and local variables get memory allocated on Stack.
c. Deallocate memory when it's no longer needed.

new: Allocates memory in C++.
delete: Deallocates memory in C++.

**************************************************************/
#include <iostream>
using namespace std;

int new_delete_operator()
{
    int *p = new int(10);
    float *q = new float(1.5);
    char *r = new char('V');

    cout << "p = " << *p << endl;
    cout << "q = " << *q << endl;
    cout << "r = " << *r << endl;

    delete p;
    delete q;
    delete r;
    return 0;
}

/* Create 1D array using new and delete operators */

int create_1D_array()
{
    int n;

    cout << "Enter the size of 1D array: " << endl;
    cin >> n;

    int *p = new int[n];

    // Input elements
    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    // Print elements
    cout << "Elements are: ";

    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }

    cout << endl;

    // Delete dynamically allocated array
    delete[] p;

    return 0;
}

int create_2D_array()
{
 // Dimesnsion of "-D array"
 int m =3, n = 4, c = 0;
 // Declare a memory block of size m*n
 int** arr = new int*[m];
 for (int i = 0;  i<m; i++)
 {
    // Declare a memory block of size n
    arr[i] = new int[n];

 }
 //Traverse the 2-D array
 for(int i = 0; i<m; i++)
 {
    for(int j = 0; j<n; j++)
    {
        arr[i][j] = ++c;
    }
 }

 	// Print the 2D array
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			// Print the values of
			// memory blocks created
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

    // Delete the array created
	for (int i = 0; i < m; i++)
    {
       delete[] arr[i]; // To delete the inner array
       
    } 
    delete[] arr; // To delete the inner array
    return 0;

}

int main()
{
    new_delete_operator();
    create_1D_array();
    create_2D_array();

    return 0;
}