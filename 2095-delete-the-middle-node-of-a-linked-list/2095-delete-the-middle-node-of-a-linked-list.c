/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    int cnt=0;
    struct ListNode * temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    if(cnt%2==0){
        temp=head;
        int mid=cnt/2;
        int cnt=1;
        while(1){
            if(cnt==mid){
                break;
            }
            cnt++;
            temp=temp->next;
        }  
        temp->next=temp->next->next;
        return head;

    }else{
        if(cnt==1){
            head=NULL;
            return NULL;
        }
        int mid=cnt/2;
        temp=head;
        cnt=1;
        while(1){
            if(cnt==mid){
                break;
            }
            cnt++;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
}