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
    ListNode* CurrentNode;
    ListNode* PrevNode = NULL;
    ListNode* NextNode;

    ListNode* reverseList(ListNode* head) 
    {
       NextNode = CurrentNode  = head;
       while(NextNode!=NULL) 
       {
          NextNode = CurrentNode->next;
          CurrentNode->next = PrevNode;
          PrevNode = CurrentNode;
          CurrentNode = NextNode;
       }
       head = PrevNode;
       return head;
    }
};