class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next; // Store the next node
            current->next = prev;     // Reverse the pointer

            // Move pointers one position ahead
            prev = current;
            current = nextNode;
        }

        // Update head to point to the new first node (which was originally the last node)
        head = prev;

        return head;
    }
};
