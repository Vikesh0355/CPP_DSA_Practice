#include <cstring>
using namespace std;
class Solution 
{
    public:
        string addStrings(string num1, string num2) 
        {
        std::string result = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        // Loop through both strings from the end toward the start
        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = 0, digit2 = 0;

            if (i >= 0) {
                digit1 = num1[i] - '0';
                i--;
            }

            if (j >= 0) {
                digit2 = num2[j] - '0';
                j--;
            }

            int sum = digit1 + digit2 + carry;
            result += (sum % 10 + '0');  // add the current digit
            carry = sum / 10;            // update the carry
        }

        std::reverse(result.begin(), result.end()); // since we built the result backward
        return result;

        }
};