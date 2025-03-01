/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode *head=NULL;
 struct ListNode *tail=NULL;
 int carry=0;
 void Add_To_List(int a,int b){
    int ld=(a+b+carry)%10;
    carry=(a+b+carry)/10;
    struct ListNode* nn=(struct ListNode*)malloc(sizeof(struct ListNode));
    nn->val=ld;
    nn->next=NULL;
    if(head==NULL){
        head=nn;
        tail=nn;
        return ;
    }
    tail->next=nn;
    tail=nn;
    return ;       
 }
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    head=NULL;
    tail=NULL;
    carry=0;
    while(l1!=NULL && l2!=NULL){
        Add_To_List(l1->val,l2->val);
        l1=l1->next;
        l2=l2->next;
    }
    while(l1!=NULL){
        Add_To_List(l1->val,0);
        l1=l1->next;
    }
    while(l2!=NULL){
        Add_To_List(l2->val,0);
        l2=l2->next;
    }
    if(carry!=0){
        Add_To_List(0,0);
    }
    return head;
}