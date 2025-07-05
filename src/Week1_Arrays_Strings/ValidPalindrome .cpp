#include <cctype>     // for isalnum, tolower
#include <algorithm>  // for reverse

class Solution {
public:
    bool isPalindrome(string str) {
        string cleaned = "";

        // Remove non-alphanumeric and convert to lowercase
        for (char c : str) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        // Compare with its reverse
        string reversed = cleaned;
        reverse(reversed.begin(), reversed.end());

        return cleaned == reversed;
    }
};
