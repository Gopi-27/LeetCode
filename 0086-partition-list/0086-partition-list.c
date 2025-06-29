/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if(head == NULL)return head;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = -300;
    dummy->next = head;
    head = dummy;


    struct ListNode* temp = head;
    while(temp->next){
        if(temp->next->val >= x){
            break;
        }
        temp = temp->next;
    }
    if(temp->next == NULL)return head->next;
    struct ListNode* GreNode = temp;
    while(temp->next){
        while(temp->next && temp->next->val >= x)temp = temp->next;
        if(temp->next == NULL)return head->next;
        struct ListNode* Cur = temp->next;
        temp->next = Cur->next;

        Cur->next = GreNode->next;
        GreNode->next = Cur;

        GreNode = Cur;
    }
    return head->next;

}