/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
        struct ListNode *thead=head;
        int cnt=0;
        while(thead!=NULL){
            cnt++;
            thead=thead->next;
        }
        int ans=0;
        while(head!=NULL){
            ans+=(head->val)*pow(2,cnt-1);
            cnt--;
            head=head->next;
        }
        return ans;
}