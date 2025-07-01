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
    ListNode* mergeInBetween(ListNode* head, int a, int b, ListNode* list2) {
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        head = temp;
        int cnt = 1;
        while(cnt < a + 1){
            temp = temp->next;
            cnt++;
        }
        ListNode* left = temp;
        while(cnt < b + 3){
            temp = temp->next;
            cnt++;
        }
        ListNode* right = temp;
        left->next = list2;
        temp = list2;
        while(temp->next)temp = temp->next;
        temp->next = right;
        return head->next;

    }
};