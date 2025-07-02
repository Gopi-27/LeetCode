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
    int pairSum(ListNode* head) {
        ListNode *slow = head,*fast = head,*prev = NULL,*cur = NULL;
        while(fast){
            fast = fast->next->next;

            cur = slow;
            slow = slow->next;
            cur->next = prev;
            prev = cur;            
        }
        int max = 0;
        while(slow){
            if(max < (slow->val + cur->val))max = slow->val + cur->val;
            cur= cur->next;
            slow =slow->next;
        }
        return max;
    }
};













