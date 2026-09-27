/*You can nest ternary operators to handle more than two outcomes, but it can make your code harder to read:*/
#include <iostream>
using namespace std;

int main()
{
    int time = 22;
    string message = (time < 12) ? "Good morning."
      : (time < 18) ? "Good afternoon."
      : "Good evening.";
    cout << message;
 return 0;
}