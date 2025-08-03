#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class LinearSearch
{
public:
    unordered_set<int> seen;

    bool FindNumberAndCheckDuplicates(vector<int>& data, int n)
    {
        bool found = false;

        for (auto value : data)
        {
            // Check for duplicate
            if (seen.count(value))
            {
                cout << "Duplicate found: " << value << endl;
            }

            // Check if this value is the target
            if (value == n)
            {
                found = true;
            }

            seen.insert(value);
        }

        return found;
    }
};

int main()
{
    LinearSearch L;
    vector<int> data = {10, 20, 30, 43, 56, 60, 20, 56};
    int n = 56;

    if (L.FindNumberAndCheckDuplicates(data, n))
        cout << "Number " << n << " is Found" << endl;
    else
        cout << "Number " << n << " is Not Found" << endl;

    return 0;
}
