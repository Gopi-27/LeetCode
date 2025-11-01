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
    bool Check(vector<int>&nums,int key){
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] == key)return true;
            else if(nums[mid] < key)low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(),nums.end());
        ListNode* temp = new ListNode(-1,head);
        head = temp;
        while(temp->next){
           if(Check(nums,temp->next->val))
                temp->next = temp->next->next;
           else
                temp = temp->next;
        }
        return head->next;
    }
};