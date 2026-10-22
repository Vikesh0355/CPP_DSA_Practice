/* A queue stores multiple elements in a specific order, called FIFO.*/
/* In a queue, you can only access the element at the front or the back, using .front() and .back() respectively:*/
/* unlike list in queue we can only add element in the last*/

#include <iostream>
#include <queue>
using namespace  std;
int mian()
{
  queue<string> cars;
   /* add element to the queue*/
  cars.push("Volvo");
  cars.push("BMW");
  cars.push("Ford");
  cars.push("Mazda");
  // Access the front element (first and oldest)
  cout << cars.front();  // Outputs "Volvo"

    // Access the back element (last and newest)
    cout << cars.back();  // Outputs "Mazda" 
   // Change the value of the front element
    cars.front() = "Tesla";

    // Change the value of the back element
    cars.back() = "VW";

    // Access the front element
    cout << cars.front();  // Now outputs "Tesla" instead of "Volvo"

    // Access the back element
    cout << cars.back();  // Now outputs "VW" instead of "Mazda"

    // Remove the front element (Volvo)
    cars.pop();

    // Access the front element (Now BMW)
   cout << cars.front();
   /* get the size of queue */
   cout << cars.size();
   /* check if the queue is empty()*/
   cout << cars.empty(); // Outputs 1 (The queue is empty)
   return 0;
} 

