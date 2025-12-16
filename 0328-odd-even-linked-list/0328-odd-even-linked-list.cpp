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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ehead = new ListNode(-1);
        ListNode* ohead = new ListNode(-1);
        ListNode* etail = ehead;
        ListNode* otail = ohead;

        int i = 1;
        while(head){
            if(i % 2 == 1){
                otail->next = head;
                otail = otail->next;
            }else{
                etail->next = head;
                etail = etail->next;
            }
            head = head->next;
            i++;
        }
        otail->next = ehead->next;
        etail->next = NULL;
        return ohead->next;
    }
};