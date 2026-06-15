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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int fidx = -1;
        int pidx = -1;
        int idx = 0;
        vector<int>Ans = {INT_MAX,-1};
        while(head->next && head->next->next){
            if((head->val < head->next->val && head->next->val > head->next->next->val) || head->val > head->next->val && head->next->val < head->next->next->val){
                if(pidx == -1){
                    pidx = idx + 1;
                    fidx = idx + 1;
                }else{
                    Ans[0] = min(Ans[0],idx + 1 - pidx);
                    Ans[1] = idx + 1 - fidx;
                    pidx = idx + 1;
                }
            }
            head = head->next;
            idx++;
        }
        if(Ans[1] == -1)return {-1,-1};
        return Ans;
    }
};