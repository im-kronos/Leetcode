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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int n=0;
        ListNode* curr = head;
        while(curr!=nullptr)
        {
            n++;
            curr=curr->next;
        }

         int del=n-k;
         if(del==0)
         {
            ListNode* temp = head;
            head = head->next;
            return head;

         }

         curr=head;
         for(int i=0;i<del-1;i++)
         {
             curr=curr->next;
         }
         curr->next=curr->next->next;
         return head;        
    }
};