/* Interators are used to access and iterate  through element od data structure by pointing to them */
#include <iostream>
#include <vector>

int main()
{
   vector<string> cars = { "Volvo", "BMW", "Ford", "Mazda"};
   vector<string>::iterators it;
   for(it= cars.begin(); it != cars.end(); ++it)
   {
     cout<<*it<<"\n";
   }
}

