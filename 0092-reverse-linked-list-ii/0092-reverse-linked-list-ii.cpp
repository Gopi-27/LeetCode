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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* myhead = new ListNode(-1);
        myhead->next = head;
        ListNode *mytail = myhead,*first,*prev = NULL,*curr = head;
        left--;
        while(left--){
            right--;
            mytail = curr;
            curr = curr->next;
        }
        first = curr;
        while(right--){
            ListNode* nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        mytail->next = prev;
        first->next = curr;
        
        return myhead->next;
    }
};