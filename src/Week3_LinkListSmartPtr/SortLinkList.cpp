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
class Solution
{
    public:
    // Main function to sort the linked list
    ListNode* sortList(ListNode* head)
    {
        // Step 1: Calculate the length of the linked list
        int len = 0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;  // Traverse the list to find its length
            len++;
        }

        // Step 2: Create a dummy node to simplify the merge process
        ListNode* dummy = new ListNode(0);
        dummy->next = head;  // Connect the dummy node to the head of the list

        // Step 3: Perform bottom-up merge sort in an iterative manner
        for(int i = 1; i < len; i *= 2)  // Start with size 1, then 2, 4, 8, ...
        {
            ListNode* curr = dummy->next;  // Start from the head of the list
            ListNode* tail = dummy;  // Tail is the node where we attach the merged result
            while(curr)
            {
                // Step 4: Split the current list into two parts of size 'i'
                ListNode* left = curr;
                ListNode* right = split(left, i);  // Split the left part of size 'i'
                curr = split(right, i);  // Move the current pointer forward by 'i'

                // Step 5: Merge the two sorted sublists 'left' and 'right'
                tail->next = merged(left, right);

                // Step 6: Move the 'tail' pointer to the last node of the merged list
                while(tail->next) 
                    tail = tail->next;
            }
        }
        // Return the sorted list starting from the node after dummy (skip dummy node)
        return dummy->next;
    }

    private:
    // Function to merge two sorted linked lists (list1 and list2)
    ListNode* merged(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode(0);  // Dummy node to simplify merging
        ListNode* tail = dummy;  // Tail pointer to build the merged list
        
        // Merge the two lists by comparing node values
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                tail->next = list1;  // Attach list1's node to the merged list
                list1 = list1->next;  // Move to the next node in list1
            }
            else
            {
                tail->next = list2;  // Attach list2's node to the merged list
                list2 = list2->next;  // Move to the next node in list2
            }
            tail = tail->next;  // Move the tail pointer forward
        }

        // Step 7: Attach any remaining nodes from either list1 or list2
        tail->next = list1 ? list1 : list2;

        // Return the merged list starting from the node after dummy (skip dummy node)
        return dummy->next;
    }

    // Function to split the linked list into two parts of size 'size'
    ListNode* split(ListNode* head, int size)
    {
        ListNode* current = head;

        // Traverse the list to find the node at position 'size'
        for (int i = 1; current && i < size; i++) 
        {
            current = current->next;  // Move the 'current' pointer forward
        }

        // If the current node is NULL, the list has fewer than 'size' elements
        if(!current) 
            return nullptr;

        // Step 8: Split the list into two parts
        ListNode* next = current->next;  // Store the second part of the list
        current->next = nullptr;  // Break the link to the second part

        return next;  // Return the second part of the list
    }
};
