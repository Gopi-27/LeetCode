/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int GetLen(ListNode* head){
        int n = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            n += 2;
        }
        if(!fast)return n;
        return n + 1;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = GetLen(head);
        int quo = n/k;
        int rem = n % k;
        vector<ListNode*>ans;
        for(int i = 0; i < k; i++){
            ListNode* myhead = NULL;
            ListNode* mytail = NULL;
            for(int q = 0; q < quo; q++){
                if(!myhead){
                    myhead = head;
                    mytail = head;
                    head = head->next;
                }else{
                    mytail = head;
                    head = head->next;
                }
            }
            if(rem){
                if(!myhead){
                    myhead = head;
                    mytail = head;
                    head = head->next;
                }else{
                    mytail = head;
                    head = head->next;
                }
                rem--;
            }
            ans.push_back(myhead);
            if(mytail)mytail->next = NULL;
        }
        return ans;
    }
};