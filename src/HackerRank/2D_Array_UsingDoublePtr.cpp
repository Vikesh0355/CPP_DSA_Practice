#include <iostream>
using namespace std;


int main()
{
	// Dimensions of the array
	int m = 3, n = 4, c = 0;

	// Declare memory block of size M
	int** arr = new int*[m];

	for (int i = 0; i < m; i++) {

		// Declare a memory block
		// of size n
		arr[i] = new int[n];
	}

	// Traverse the 2D array
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			// Assign values to the
			// memory blocks created
			arr[i][j] = ++c;
		}
	}

	// Traverse the 2D array
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			/* Print the values of memory blocks created */
			
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	// Delete the array created
	for (int i = 0; i < m; i++) /*To delete the inner array */
								
		delete[] arr[i];
	delete[] arr;  /* To delete the outer array which contained the pointers of all the inner arrays */
				
				 

	return 0;
}

/*  g++ -std=c++14 2D_Array_UsingDoublePtr.cpp -o 2D_Array_UsingDoublePtr -pthread */
/* ./2D_Array_UsingDoublePtr  */