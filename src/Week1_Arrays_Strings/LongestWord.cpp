#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

std::string LongestWord(const std::string& sen) {
    std::stringstream ss;

    for (char c : sen) {
        if (std::isalnum(c) || std::isspace(c)) {
            ss << c;
        }
    }

    std::string word, longest;
    while (ss >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }

    return longest;
}

int main() {
    std::string input = "fun&!! time";
    std::cout << "Output: " << LongestWord(input) << std::endl;

    return 0;
}
