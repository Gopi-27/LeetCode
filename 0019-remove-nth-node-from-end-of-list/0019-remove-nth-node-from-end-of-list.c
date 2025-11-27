/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int cnt=0;
    struct ListNode * temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    if(cnt==1){
        return NULL;
    }
    int idx=cnt-n;
    if(idx==0){
        head=head->next;
        return head;
    }
    cnt=1;
    temp=head;
    while(1){
        if(cnt==idx){
            break;
        }
        cnt++;
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
}