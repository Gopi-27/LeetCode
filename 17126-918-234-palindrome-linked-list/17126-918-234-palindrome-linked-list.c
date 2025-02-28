/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* Head=NULL;
 struct ListNode* tail=NULL;
 void Add_To_List(int val){
    struct ListNode* nn=(struct ListNode *)malloc(sizeof(struct ListNode));
    nn->val=val;
    nn->next=NULL;
    if(Head==NULL){
        Head=nn;
        tail=nn;
        return ;
    }
    nn->next=tail;
    tail=nn;
    return;
 }
bool isPalindrome(struct ListNode* head) {
    Head=NULL;
    tail=NULL;
    struct ListNode* temp=head;
    while(temp!=NULL){
        Add_To_List(temp->val);
        temp=temp->next;
    }
    int cnt=0;
    while(head!=NULL){
        if(head->val!=tail->val){
            cnt++;
            break;
        }
        head=head->next;
        tail=tail->next;
    }
    if(cnt==0){
        return true;
    }else{
        return false;
    }
}