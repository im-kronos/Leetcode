/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   int length(ListNode *root)
   {
    int l=0;
    while(root)
    {
        l++;
        root=root->next;
    }
    return l;
   }


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       int l1=0;
       int l2=0;
       l1=length(headA);
       l2=length(headB);

       int diff=abs(l1-l2);
       if(l1>l2)
       {
        while(diff--)
        {
            headA=headA->next;
        }
       }
       else
       {
         while(diff--)
        {
            headB=headB->next;
        }
       }

       while(headA && headB && headA!=headB)
       {
        headA=headA->next;
        headB=headB->next;
       }

       return headA;
        
    }
};