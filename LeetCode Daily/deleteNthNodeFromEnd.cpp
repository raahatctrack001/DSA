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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //get the size of linked list
        auto getSize = [&](ListNode *root){
            int count = 0;
            while(root){
                count++;
                root = root->next;
            }
            return count;
        };

        int listSize = getSize(head);
        //nth node from end == (listSize-n)th node from start
        int nthNodeFromStart = listSize-n; //index-0 based

        //handling possible edge cases
        if(nthNodeFromStart < 0 or nthNodeFromStart > listSize)
            return head;
            
        //head deletion
        if(nthNodeFromStart == 0){
            ListNode *toDelete = head;
            head = head->next;
            delete toDelete;
        }
        else{
            ListNode *currentNode = NULL;
            ListNode *toDelete = head;
            for(int i = 0; i < nthNodeFromStart; i++){
                currentNode = toDelete;
                toDelete = toDelete->next;
            }
            ListNode *temp = toDelete;
            currentNode->next = toDelete->next;
            delete temp;
        }
        return head;
    }
};