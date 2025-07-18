#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
using namespace std;

class Solution 
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);  // Dummy node to simplify edge case handling
        ListNode* current = dummy;  // Pointer to the last node in the result list
        int carry = 0;  // Variable to store the carry
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) 
        {
            int sum = carry;  // Start with the carry from the previous iteration
            
            if (l1 != nullptr) {
                sum += l1->val;  // Add the value from l1 if it exists
                l1 = l1->next;  // Move to the next node in l1
            }
            
            if (l2 != nullptr) {
                sum += l2->val;  // Add the value from l2 if it exists
                l2 = l2->next;  // Move to the next node in l2
            }
            
            // Update the carry and the current node's value
            carry = sum / 10;  // Carry for the next iteration
            current->next = new ListNode(sum % 10);  // Store the current digit (sum % 10)
            current = current->next;  // Move the pointer to the new last node
        }
        
        return dummy->next;  // Return the next node of dummy (the actual head of the result list)
    }
};
