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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *temp = head,*prev,*cur;
        head = temp->next;
        
        prev = temp;
        cur = temp->next;
        temp = cur->next;
        cur->next = prev;


        while(temp && temp->next){
            prev->next = temp->next;
            prev = temp;
            cur = temp->next;
            temp = cur->next;
            cur->next = prev;
        }
        
        prev->next = temp;
        return head;
    }
};