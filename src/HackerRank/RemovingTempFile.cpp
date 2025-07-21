#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Predicate function to check for .tmp extension
bool hasTmpExtension(const std::string& filename) {
    return filename.size() >= 4 && filename.substr(filename.size() - 4) == ".tmp";
}

int main() {
    std::vector<std::string> filenames = {
        "file1.txt", "file2.tmp", "document.pdf", "tempfile.tmp", "image.png"
    };

    // Remove .tmp files using std::remove_if
    auto new_end = std::remove_if(filenames.begin(), filenames.end(), hasTmpExtension);

    // Erase the .tmp files from the vector
    filenames.erase(new_end, filenames.end());

    // Print the remaining filenames
    std::cout << "Remaining filenames:" << std::endl;
    for (const auto& filename : filenames) {
        std::cout << filename << std::endl;
    }

    return 0;
}
