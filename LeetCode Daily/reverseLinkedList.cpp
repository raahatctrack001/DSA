/*
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *curr, *next = head;
        curr = prev = NULL;
        while(next){
            curr = next;
            next = next->next;
            curr->next  = prev;
            prev = curr;
        }
        return curr;
    }
};