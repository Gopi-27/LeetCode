/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int Gcd(int a,int b){
    if(a == 0)return b;
    if(b == 0)return a;
    if(a > b)return Gcd(a-b,b);
    return Gcd(a,b-a);
}
struct ListNode* C_A_N(int val){
    struct ListNode* nn = (struct ListNode*)malloc(sizeof(struct ListNode));
    nn->val = val;
    nn->next = NULL;
    return nn;
}
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode* temp = head;
    while(temp->next != NULL){
        struct ListNode* nn = C_A_N(Gcd(temp->val,temp->next->val));
        nn->next = temp->next;
        temp->next = nn;
        temp = nn->next;
    }
    return head;
}