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
    // lst -> 2 - > 1
    // head   1 -> 2 -> 3 -> 4
    //        4 -> 3 -> 2 -> 1
    // last, next start;
    pair<bool,pair<ListNode*,ListNode*>> ReverseK(ListNode* head,int k){
        int cnt = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(cnt < k && curr){
            ListNode* nxtPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxtPtr;
            cnt++;
        }
        return {cnt == k,{prev,curr}};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)return head;
        ListNode* myhead = new ListNode(-1);
        ListNode* mytail = myhead;
        while(1){
            ListNode* first = head;
            pair<bool,pair<ListNode*,ListNode*>> res = ReverseK(head,k);
            if(res.first){
                mytail->next = res.second.first;
                mytail = first;
                head = res.second.second;
            }else{
                head = res.second.first;
                break;
            }
        }
        pair<bool,pair<ListNode*,ListNode*>> res = ReverseK(head,k);
        mytail->next = res.second.first;
        return myhead->next;
    }
};
