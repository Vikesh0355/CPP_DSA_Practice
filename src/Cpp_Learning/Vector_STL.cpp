/* STL is a library that consist of different data structures and algorithms to effectively store and manipulate data.*/

/* vector : Stores elements like an array but can be dynamically chnage in size. Adding and removing of elements are usually done at the end. Elements can be accessed by index.*/

/* list: Stores element sequentially, where each element is connected to the nex. Adding and removing of elements can be done at both ends. Not accessible by index.*/

/* stack: Stores elements in specific order, called LIFO, ehere element can only be added and removed from Top. Not accessible by index*/

/* Queue: Stores element in specific order called FIFO, where elements are added at the end and removed from the top. Not accessible by index**/

/* Deque: Stores elements in double ended queue, where elements can be added and removed from both. Elements can be accessible by index */

/* set: Stores unique elements. not acesible by index*/

/* Map: Stores element in key/value pairs.  Accessible by key not by index.*/

 /* Example*/
  #include <vector> 
  #incude <list>
  #include <set>
  #include <map>
  #include <stack>
  #include <queue>

/* create a vectore: 
vectore <type> vectorName */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> cars = {"Volvo", "BMW", "VW", "Ford"};

    for (string car : cars) {
        cout << car <<"\t"; 
    }

    /* Access a vector by index*/
    cout<<"\n"<<cars[2]<<endl; //output:VW

    /* Get the first element*/
    cout<<cars.front()<<endl; //output: Volvo

    /* get the last element */
    cout<<cars.back()<<endl; // output: Ford

    /* To access an element at a specified index, you can use the .at() function and specify the index number*/
    /* Get the second element */
   cout << cars.at(1)<<endl; // BMW
   /*Get the third element */
   cout << cars.at(2)<<endl; //VW

   // Change the value of the first element
   cars[0] = "Opel";

   cout << cars[0]<<endl;  // Now outputs Opel instead of Volvo
   
   /*However, it is safer to use the .at() function:*/
   cars.at(0) = "opel"; // chnaged the value of first element
   cout<<cars.at(0)<<endl;
    return 0;
}

/* The biggets difference between a vector and an array is that vectore can grow dynamically. that means you can add or remove the elements from the vector.
 To add an element to the vector, you can us ethe .push_back() function, which will add an element at the end of the vector*/

 vector<string> cars = { "Volvo", "BMW", "Ford", "mazda"};
 cars.push_back("Tesla");

 // You can add as may elements as you want
 // Example

  cars.push_back("Tesla");
  cars.push_back("Tata Punch");
  cars.push_back("BYD");
  cars.push_back("Mini");

  /* To reomove an element from the vector, you can use the .po_back(), function, which removes an element from the end of the vector*/

 vector<string> cars = { "Volvo", "BMW", "Ford", "mazda"};
 cars.pop_back();

/* To find out how many elements a vector has, use the .size() function*/

vectore<string> cars  = { "volvo", "BMW", "Ford", "Mazda"};
cout<<cars.size()<<endl;

 /* Check if vector is empty*/
 vector<string> cras;
 cout<<cars.empty();

 /* Loop through vector : You can loop through the vector element by using a for loop combned with the .size() function*/
 vector<string> cars = { "volvo", "BMW", "Tata Punch", "scorpio"};
 for(int i = 0; i<cars.size(); i++)
 {
    cout<<cars[i]<<"\t";
 }