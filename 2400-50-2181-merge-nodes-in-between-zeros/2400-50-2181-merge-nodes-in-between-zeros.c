/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* tail = head->next;
    struct ListNode* curnode = head;
    while(1){
        while(tail->val != 0){
            curnode->val += tail->val;
            tail = tail->next;
        }
        if(tail->next != NULL){
            curnode = curnode->next;
            curnode->val = 0;
            tail = tail->next;
        }else{
            curnode->next = NULL;
            break;
        }
    }
    return head;
}