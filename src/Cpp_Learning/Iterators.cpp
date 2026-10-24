/* Interators are used to access and iterate  through element od data structure by pointing to them */
#include <iostream>
#include <vector>
using namespace std;
int main()
{
   vector<string> cars = { "Volvo", "BMW", "Ford", "Mazda"};
   vector<string>::iterator it;
   for(it= cars.begin(); it != cars.end(); ++it)
   {
     cout<<*it<<"\n";
   }
   // Point to the first element in the vector
  it = cars.begin();
   // Modify the value of the first element
  *it = "Tesla";
  return 0:
}

