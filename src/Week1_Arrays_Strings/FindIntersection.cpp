#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> parseList(const string& s) {
    vector<int> result;
    stringstream ss(s);
    string token;
    while (getline(ss, token, ',')) {
        result.push_back(stoi(token));
    }
    return result;
}

string FindIntersection(string strArr[], int arrLength) {
    // Parse both input strings into vectors
    vector<int> arr1 = parseList(strArr[0]);
    vector<int> arr2 = parseList(strArr[1]);

    vector<int> intersection;

    // Check each number in arr1 if it exists in arr2
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                intersection.push_back(arr1[i]);
                break;  // Found it, no need to keep looking in arr2
            }
        }
    }

    if (intersection.empty())
        return "false";

    // Build result string from intersection vector
    string result = "";
    for (int i = 0; i < intersection.size(); i++) {
        if (i > 0) result += ",";
        result += to_string(intersection[i]);
    }

    return result;
}




// keep this function call here
int main(void) { 
   
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << FindIntersection(A, arrLength);
  return 0;
    
}