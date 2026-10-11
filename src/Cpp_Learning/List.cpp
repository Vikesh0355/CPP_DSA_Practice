
/* A list is similiar to a vector in that it can store multiple elements of the same type and dynmically grow in size.*/
/* However, two major diffrences between lists and vector are:*/
/* 1. You can add and remove elements from both the beginning and at the end of a list, while vector are generally optimized for adding and removing at the end*/
/* 2. Unlike vector, a list doesn#t support random access, meaning you can#t directly jump to a specific index , or access element by an index numbers*/

/* create a list: To create a list, use the list keyword and specify the type of values it should store within angle bracketand then the nam eof the list*/
/*Example:  list<string> cars*/

#include <iostream>
#include <vector>
#include <string>
#include<list>
using namespace std;

list<string> cars = {"Volvo", "BMW", "ford", "Mazda"};
int main()
{
 for(string car: cars)
 {
   cout<<car<<"\t";
 }
 cout<<"\n";
 /* Acces a list*/
 cout<<cars.front()<<endl; // output Volvo
 cout<<cars.back()<<endl; // Mazda

 /* Change a list*/
 cars.front() = "Tata Punch";
 cars.back() = "Fortuner";

 cout<<cars.front()<<endl; // output Tata Punch
 cout<<cars.back()<<endl; // Fortuner
 return 0;
}

/* Remove List Elements*/
list<string> cars  = { "Volvo", "BMW", "Ford", "Mazda"};
// Remove the first element
cars.pop_front();

// Remove the last element
cars.pop_back();

// Check the size of list
cout<<cars.size();

// Check if list is Empty
cout<<cars.empty();