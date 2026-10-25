/* C++ sets: A sets stores uniqueu element where they:*/
/* Are sorted automatically in ascending order
/* Are unique , meanng equal or duplicate values are ignored */
/* can be added or remove but the value of an existing element cannot be chnaged */
/* Cannot be accessed by an index number, because the order is based on sorting and not indexing */
#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<string>cars = {"Volvo", "BMW", "ford", "Mazda"};
    for(string car: cars)
    {
        cout<<car<<endl;
    }
    /* To add elements to a set, you can use the .insert() function:*/
    cars.insert("Toyota");
    cars.insert("Audi");
    /* To remove specific elements from a set, you can use the .erase() function: */
    cars.erase("Mazda");
   /* To find out how many elements a set has, use the .size() function: */ 
   cout << cars.size()<<endl; 
    return 0;
}
