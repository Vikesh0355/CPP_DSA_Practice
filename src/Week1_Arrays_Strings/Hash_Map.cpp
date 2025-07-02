#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // 1. Declare an unordered_map with string keys and int values
    unordered_map<string, int> map;

    // 2. Insert key-value pairs
    map["apple"] = 5;             // Insert using operator[]
    map.insert({"banana", 3});    // Insert using insert()

    // 3. Access elements
    cout << "apple count: " << map["apple"] << endl;  // Outputs 5

    // 4. Modify element
    map["apple"] = 10;
    cout << "apple updated count: " << map["apple"] << endl;  // Outputs 10

    // 5. Check if key exists using find()
    if (map.find("banana") != map.end()) {
        cout << "banana found with count: " << map["banana"] << endl;
    } else {
        cout << "banana not found" << endl;
    }

    if (map.find("cherry") == map.end()) {
        cout << "cherry not found" << endl;
    }

    // 6. Iterate over all key-value pairs
    cout << "\nIterating over all elements:" << endl;
    for (const auto& pair : map) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 7. Erase a key-value pair
    map.erase("banana");
    cout << "\nAfter erasing banana:" << endl;
    for (const auto& pair : map) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    // 8. Size of the map
    cout << "\nSize of map: " << map.size() << endl;

    // 9. Clear the map
    map.clear();
    cout << "Map cleared. Size now: " << map.size() << endl;

    return 0;
}


/*  g++ -std=c++14 Hash_Map.cpp -o Hash_Map -pthread */
/* ./Hash_Map  */