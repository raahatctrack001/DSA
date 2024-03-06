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
    bool hasCycle(ListNode *head) {
        if(!(head and head->next)) return false;

        ListNode *p, *q;
        p = q = head;
        do{
            p = p->next;
            q = q->next;
            q = q ? q->next : NULL;
        }while(p and q and (p != q));
        return p == q;
    }
};