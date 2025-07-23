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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Create a dummy node that points to the head of the list
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 1: Move `prev` to the node just before the "left" position
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // `prev` is now at the node before the "left" node
        ListNode* start = prev->next;  // The first node of the sublist to be reversed
        ListNode* then = start->next;  // The node that will be moved to the front

        // Step 2: Reverse the sublist from left to right
        for (int i = 0; i < right - left; ++i) {
            start->next = then->next;  // Disconnect `then` from the sublist
            then->next = prev->next;   // Move `then` to the front of the sublist
            prev->next = then;         // Attach `then` to the previous node
            then = start->next;        // Move `then` forward
        }

        return dummy->next;
    }
};
