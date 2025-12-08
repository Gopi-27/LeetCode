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
    ListNode* Reverse(ListNode* head){
        ListNode* prev = NULL,*curr = head,*next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* temp = prev;
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        return prev; 
    }
    void reorderList(ListNode* head) {
        if(!head->next)return;
        ListNode* slow = head;
        ListNode* fast = head;
        int n = 0;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            n += 2;
        }
        n /= 2;
        cout << n << endl;
        ListNode* lst = Reverse(slow);
        ListNode* prev;
        while(n--){
            ListNode* temp = head->next;
            head->next = lst;
            prev = lst;
            lst = lst->next;
            prev->next = temp;            
            head = temp;            
        }
        if(lst){
            prev->next = lst;
            lst->next = NULL;
        }else prev->next = NULL;
    }

    // 1 -> 2 -> 3  h
    // 4 -> 5 -> 6 -> 7


};