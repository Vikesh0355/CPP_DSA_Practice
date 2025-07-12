

#include <iostream>
#include <string>
#include <cctype>  // for isalpha, isalnum
using namespace std;

string CodelandUsernameValidation(string str) {
    int n = str.size();

    // Rule 1: Check length
    if (n < 4 || n > 25)
        return "false";

    // Rule 2: Must start with a letter
    if (!isalpha(str[0]))
        return "false";

    // Rule 3: Must only contain letters, digits, or underscore
    for (char c : str) {
        if (!isalnum(c) && c != '_')
            return "false";
    }

    // Rule 4: Cannot end with underscore
    if (str[n - 1] == '_')
        return "false";

    return "true";
}


// keep this function call here
int main(void) { 
   
  cout << CodelandUsernameValidation(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}