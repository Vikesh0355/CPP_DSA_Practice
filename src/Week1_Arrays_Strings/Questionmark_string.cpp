#include <iostream>
#include <string>
using namespace std;

string QuestionsMarks(string str) {
  bool valid_pair_found = false;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      int num1 = str[i] - '0';
      int count = 0;

      for (int j = i + 1; j < str.length(); j++) {
        if (str[j] == '?') {
          count++;
        } else if (str[j] >= '0' && str[j] <= '9') {
          int num2 = str[j] - '0';

          if (num1 + num2 == 10) {
            if (count != 3)
              return "false";
            valid_pair_found = true;
          }
          break; // move to next outer loop digit
        }
      }
    }
  }

  return valid_pair_found ? "true" : "false";
}
