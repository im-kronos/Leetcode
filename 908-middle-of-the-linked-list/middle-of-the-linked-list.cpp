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
  int solve1(ListNode* root,int count)
  {
      ListNode *temp=root;
      while(temp!=NULL)
      {
          count++;
          temp=temp->next;
      }
      return count;
  }

  ListNode* solve2(ListNode *root,int middle)
  {
      while(middle!=0)
      {
          root=root->next;
          middle--;

      }
      ListNode* temp=root;
      //temp=root->next;
      //root->next=temp;
      return temp; 
  }




    ListNode* middleNode(ListNode* root) {
        int count=solve1(root,0);
        int middle=count/2;
        cout<<middle;
        return solve2(root,middle);
    }
};