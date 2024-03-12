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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *root = new ListNode(0);
        root->next = head;
        
        unordered_map<int, ListNode* > alreadySeen;
        alreadySeen[0] = root;

        int prefixSum = 0;
        while(head){
            prefixSum += head->val;
            
            if(alreadySeen.find(prefixSum) != alreadySeen.end()){
                int preSumCopy = prefixSum;
                ListNode *prev = alreadySeen[preSumCopy];
                ListNode *toLink = prev;

                while(prev != head){
                    prev = prev->next;
                    preSumCopy += prev->val;
                    if(prev != head)
                        alreadySeen.erase(preSumCopy);
                }
                toLink->next = head->next;
            }
            else{
                alreadySeen[prefixSum] = head;
            }
            head = head->next;
        }
        return root->next;
    }
};