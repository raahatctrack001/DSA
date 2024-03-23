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
    void reorderList(ListNode* head) {
        if(!head or !head->next or !head->next->next)
            return;

        ListNode *penultimateNode = head;
        while(penultimateNode->next->next){
            penultimateNode = penultimateNode->next;
        }

        penultimateNode->next->next = head->next;
        head->next = penultimateNode->next;
        penultimateNode->next = NULL;

        reorderList(head->next->next);
    }
};