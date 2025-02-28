/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode * Head=NULL;
 struct ListNode * Tail=NULL;
 void Add_To_List(int val){
    struct ListNode *newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
    newnode->val=val;
    newnode->next=NULL;
    if(Head==NULL){
        Head=newnode;
        Tail=newnode;
        return;
    }
    Tail->next=newnode;
    Tail=newnode;
    return;

 }
struct ListNode* removeElements(struct ListNode* head, int val) {
    Head=NULL;
    Tail=NULL;
    while(head!=NULL){
        if(head->val!=val){
            Add_To_List(head->val);
        }
        head=head->next;
    }
    return Head;
}