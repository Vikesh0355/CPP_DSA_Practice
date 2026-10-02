/* Abstraction means  exposing only what the user needs while hiding how the something is implemented */

#include <iostream>
using namespace std;

class Car
{
    public:
    void start()
    {
      // Internally
      // fuel injection
      // ignition
      // Engine control
      //etc
    }
};

/* Here user simply does*/
int main()
{
   car obj;
   car.start();
   return 0;
}
 /* They don't need to know all the internal operations required to start the engine*/
