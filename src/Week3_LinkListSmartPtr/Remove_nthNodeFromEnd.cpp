/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
 // Create a dummy node to handle edge cases where head needs to be removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Two pointers: one will be n steps ahead of the other
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move first pointer to the n-th node ahead
        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }
        
        // Move both pointers until first reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Second is now just before the node to be deleted
        ListNode* toDelete = second->next;
        second->next = second->next->next;
        
        delete toDelete; // Free the memory of the node to be deleted
        
        // Return the updated list, starting from the original head
        ListNode* newHead = dummy->next;
        delete dummy;  // Clean up the dummy node
        
        return newHead;
    }
};