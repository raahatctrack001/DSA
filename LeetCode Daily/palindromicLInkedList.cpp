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
    ListNode *reverse(ListNode *head){
        ListNode *prev, *curr, *next;
        prev = NULL;
        curr = NULL;
        next = head;
        while(next){
            curr = next;
            next = next->next;
            curr->next = prev;
            prev = curr;
        }
        return curr;
    }

public:
    bool isPalindrome(ListNode* head) {
        
        if(!(head and head->next))
            return true;

        ListNode *slow, *fast;
        slow = head;
        fast = head->next;
        while(fast){          
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        slow->next = reverse(slow->next);
        ListNode *start = head;
        ListNode *mid = slow->next;

        while(mid != NULL){
            if(start->val != mid->val)
                return false;

            start = start->next;
            mid = mid->next;
        }
        return true;
    
    }
};