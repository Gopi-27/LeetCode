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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* myhead = new ListNode(-1);
        ListNode* mytail = myhead;
        while(head){
            if(!head->next){
                mytail->next = head;
                mytail = mytail->next;
                head = head->next;
            }else{
                if(head->val == head->next->val){
                    int key = head->val;
                    while(head && head->val == key)head = head->next;
                }else{
                    mytail->next = head;
                    mytail = mytail->next;
                    head = head->next;
                }
            }
        }
        mytail->next = NULL;
        return myhead->next;
    }
};