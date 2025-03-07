/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode Node;
struct ListNode* middleNode(struct ListNode* head) {
    Node * slow = head;
	Node * fast = head;
	while(1){
		if(fast == NULL){
			break;
		}
		if(fast->next == NULL){
			break ;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
