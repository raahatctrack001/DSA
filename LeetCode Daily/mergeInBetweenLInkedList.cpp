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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *pointFrom = list1;
        ListNode *pointAt = list1;
        ListNode *secondListTail = list2;
        ListNode *tptr = list1; //travelling pointer
        int indexOfNode = 0;
        while(tptr != NULL){
            if(indexOfNode == a-1){
                pointFrom = tptr;
                cout<<pointFrom->val<<" ";

                while(secondListTail->next)
                    secondListTail = secondListTail->next;
            }

            if(indexOfNode == b+1){
                pointAt = tptr;
                cout<<pointAt->val<<endl;
            }
            tptr = tptr->next;
            indexOfNode++;
        }
        pointFrom->next = list2;
        secondListTail->next = pointAt;
        return list1;
    }
};