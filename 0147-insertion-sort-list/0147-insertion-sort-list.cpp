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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* myhead = new ListNode(-5005);
        myhead->next = new ListNode(5005);
        
        while(head){
            ListNode* curr = head;
            head = head->next;
            curr->next = NULL;

            ListNode* temp = myhead;
            while(temp->val < curr->val)temp = temp->next;
            swap(temp->val,curr->val);
            curr->next = temp->next;
            temp->next = curr;
        }
        ListNode* temp = myhead;
        while(temp->next->val != 5005)temp = temp->next;
        temp->next = NULL;
        return myhead->next;
    }
};