/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *head=NULL;
struct ListNode *tail=NULL;

void Add_To_List(int value){
        struct ListNode *newNode;
	    newNode=(struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->val=value;
		newNode->next=NULL;

	if(head==NULL){
		head=newNode;
		tail=newNode;
	return ;	
	}
	tail->next=newNode;
    tail=newNode;
    return;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    head=NULL;
    tail=NULL;
    while(list1!=NULL && list2!=NULL){
        if((list1->val)>(list2->val)){
            Add_To_List(list2->val);
            list2=list2->next;
        }else{
            Add_To_List(list1->val);
            list1=list1->next;
        }
    }
    while(list1!=NULL){
         Add_To_List(list1->val);
        list1=list1->next;
    }
    while(list2!=NULL){
        Add_To_List(list2->val);
        list2=list2->next;
    }
    return head;
}