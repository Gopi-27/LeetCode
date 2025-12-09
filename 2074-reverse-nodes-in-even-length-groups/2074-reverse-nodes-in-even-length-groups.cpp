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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* myhead = head;
        ListNode* mytail = head;
        ListNode* curr = head->next;
        int grp = 2;
        while(curr){
            if(grp % 2 == 0){
                ListNode* prev = NULL;
                ListNode* first = curr;
                int n = grp;
                while(curr && n--){
                    ListNode* nxtPtr = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nxtPtr;
                }
                if(n > 0 && n % 2 != 0){
                    curr = prev;
                    prev = NULL;
                    while(curr){
                        ListNode* nxtPtr = curr->next;
                        curr->next = prev;
                        prev = curr;
                        curr = nxtPtr;
                    }
                    mytail->next = prev;
                }else{
                    mytail->next = prev;
                    first->next = curr;
                    mytail = first;
                }
                
            }else{
                int n = grp;
                ListNode* last = mytail;
                while(curr && n){
                    mytail = curr;
                    curr = curr->next;
                    n--;
                }
                if(n % 2 == 1){
                    curr = last->next;
                    ListNode* prev = NULL;
                    while(curr){
                        ListNode* nxtPtr = curr->next;
                        curr->next = prev;
                        prev = curr;
                        curr = nxtPtr;
                    }
                    last->next = prev;
                }
            }
            grp++;
        }
        return myhead;
    }
};