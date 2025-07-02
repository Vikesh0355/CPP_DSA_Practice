#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Declare an unordered_map to store subject and score
    unordered_map<string, int> scores;

    // Inserting values
    scores["Math"] = 90;
    scores["Physics"] = 85;
    scores["Chemistry"] = 92;

    // Accessing a value
    cout << "Physics score: " << scores["Physics"] << endl;

    // Checking if a key exists
    if (scores.find("Biology") == scores.end()) {
        cout << "Biology score not found." << endl;
    } else {
        cout << "Biology score: " << scores["Biology"] << endl;
    }

    // Modifying a value
    scores["Physics"] = 88;

    // Iterating through all subjects and scores
    cout << "\nAll subject scores:\n";
    for (const auto& pair : scores) {
        cout << pair.first << " → " << pair.second << endl;
    }

    // Erasing a key
    scores.erase("Math");
    cout << "\nAfter removing 'Math':\n";
    for (const auto& pair : scores) {
        cout << pair.first << " → " << pair.second << endl;
    }

    return 0;
}

/*  g++ -std=c++14 Hash_Map.cpp -o Hash_Map -pthread */
/* ./Hash_Map  */