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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
        ListNode* temp = head;
        ListNode* last = head;
        int n = 0;
        while(temp){
            n++;
            last = temp;
            temp = temp->next;
        }
        k %= n;
        k = n - k;
        temp = head;
        while(--k)temp = temp->next;
        // cout << temp->val;
        if(!temp->next)return head;
        ListNode* nxt = temp->next;
        temp->next = NULL;
        last->next = head;
        head = nxt;
        return head;
    }
};