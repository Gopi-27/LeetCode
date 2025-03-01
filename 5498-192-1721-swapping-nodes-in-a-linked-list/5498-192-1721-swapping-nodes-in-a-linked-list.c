/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    int cnt=0;
    struct ListNode * temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    int len=cnt;
    cnt=1;
    temp=head;
    while(1){
        if(cnt==k){
            break;
        }
        cnt++;
        temp=temp->next;
    }
    struct ListNode* first=temp;
    temp=head;
    cnt=1;
    while(1){
        if(cnt==(len-k+1)){
            break;
        }
        cnt++;
        temp=temp->next;
    }
    int tempval=temp->val;
    temp->val=first->val;
    first->val=tempval;
    return head;
}