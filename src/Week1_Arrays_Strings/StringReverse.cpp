#include <iostream>
#include <cstring>
using namespace std;

string FirstReverse(string str) 
{
  
  // code goes here  
  int n = str.length();
  for(int i = 0; i<n/2; i++)
  {

    char  temp = str[n-1-i];
    str[n-1-i] = str[i];
    str[i] = temp;

  }
  return str;

}

int main(void) 
{ 
   
  cout << FirstReverse(coderbyteInternalStdinFunction(stdin));
  cout << FirstReverse2(coderbyteInternalStdinFunction(stdin));

  return 0;
    
}