/* A map stores elements in "key/value" pairs.

Elements in a map are:

Accessible by keys (not index), and each key is unique.
Automatically sorted in ascending order by their keys.*/

/* Example */
// Create a map called people that will store strings as keys and integers as values
map<string, int> people

#include<iostream>
#include<map>
using namespace std;

int main()
{
  /* Create a map that will store the name and age of diffrent people*/
  map<string, int> people = { {"john", 32}, {"vikesh", 31}, {"Hemant", 35}};
  cout<<"john is "<<people["john"]<<endl;
  cout<<"Vikesh is "<<people["vikesh"]<<endl;
  //You can also access elements with the .at() function:
  cout<<"Hemant is: "<<people.at("Hemant")<<endl;
  // Change John's value to 50 instead of 32
  people["John"] = 50;
  cout<<"John is: "<<people.at("john")<<endl;
  // Add new elements
  people["Sweta"] = 30;
 //But you can also use the .insert() function:
 people.insert({"Kasper", 20});
 // Trying to add two elements with equal keys
 people.insert({"Jenny", 22});
 people.insert({"Jenny", 30});
 // Remove an element by key
 people.erase("John");
  return 0;
}

Note: The .at() function is often preferred over square brackets [] because it throws an error message if the element does not exist: