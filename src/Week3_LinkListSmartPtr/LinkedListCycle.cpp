/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    public:
    bool hasCycle(ListNode *head) 
    {
        if (head == NULL || head->next == NULL) return false;

        ListNode *slow = head;
        ListNode *fast = head;

        // Move slow pointer by 1 and fast pointer by 2
        while (fast != NULL && fast->next != NULL) 
        {
            slow = slow->next;  // Move slow pointer by 1 step
            fast = fast->next->next;  // Move fast pointer by 2 steps

            if (slow == fast) 
            {  // Cycle detected
                return true;
            }
        }
        return false;  // No cycle   
    }
};