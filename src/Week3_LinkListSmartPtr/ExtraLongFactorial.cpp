#include <iostream>
#include <vector>

using namespace std;

void extraLongFactorials(int n)
{
    int len = 1;                     // To track the number of digits in the result
    vector<short> num{1};            // Initialize with 1, since 0! = 1 and 1! = 1

    for (int i = 2; i <= n; i++)     // Start from i = 2 since 1! = 1 is the base case
    {
        int carry = 0;               // Initialize carry to 0 for each multiplication
        for (int j = 0; j < len; j++) // Loop through all digits of the current result
        {
            int k = num[j] * i + carry;  // Multiply each digit by 'i' and add the carry
            num[j] = k % 10;             // Store the current digit (least significant digit)
            carry = k / 10;              // Carry over the remaining value
        }

        // Handle remaining carry (if any)
        while (carry) {
            num.push_back(carry % 10);   // Append the carry as new digits
            carry /= 10;                 // Update the carry
            len++;                       // Increment the length of the number
        }
    }

    // Print the result (digits are stored in reverse order)
    for (int i = num.size() - 1; i >= 0; i--) {
        cout << num[i];
    }
    cout << endl;
}

int main()
{
    extraLongFactorials(500);   // Example: Calculate 500!
    return 0;
}