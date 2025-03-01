/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int cnt=0;
    struct ListNode * temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    if(cnt%2==0){
        int mid=(cnt/2)+1;
        cnt=1;
        temp=head;
        while(1){
            if(cnt==mid){
                break;
            }
            cnt++;
            temp=temp->next;
        }
        return temp;
        
    }else{
        temp=head;
        int mid=(cnt/2)+1;
        cnt=1;
        while(1){
            if(cnt==mid){
                break;
            }
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
}