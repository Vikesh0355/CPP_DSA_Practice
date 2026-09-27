/*There is also a "for-each loop" (also known as ranged-based for loop), which is used to loop through elements in an array (or other data structures):*/
/* for (type variableName : arrayName) {
  // code block to be executed
}*/

#include <iostream>
using namespace std;
int main()
{
    string word = "Hello";
    for(char c: word){
        cout<<c<<"\t";
    }
    retrun 0;
}