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
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 0;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        while(head){
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
            n++;
        }
        vector<int>Ans(n);
        head = prev;
        nxt = NULL;
        int i = n - 1;
        while(head){
            while(nxt && nxt->val <= head->val)nxt = nxt->next;
            if(nxt)Ans[i] = nxt->val;
            else Ans[i] = 0;
            i--;
            prev = head;
            head = head->next;
            prev->next = nxt;
            nxt = prev;
        }
        return Ans;
    }
};