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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* temp = head;
        int tl = 0;
        int tr = n - 1;
        int br = m - 1;
        int bl = 0;
        vector<vector<int>>Ans(m,vector<int>(n,-1));
        int i = 0;
        int j = 0;
        while(temp){
            // top -> left to right
            i = tl;
            j = bl;
            while(temp && j <= tr){ 
                Ans[i][j] = temp->val;
                temp = temp->next;
                j++;
            }
            // right-> up to down
            i = tl + 1;
            j = tr;
            while(temp && i <= br){
                Ans[i][j] = temp->val;
                temp = temp->next;
                i++;
            }
            i = br;
            j = tr - 1;
            // Down -> right to left
            while(temp && j >= bl ){
                Ans[i][j] = temp->val;
                temp = temp->next;
                j--;
            }
            // Left - > down to up
            i = br - 1;
            j = bl;
            while(temp && i > tl){
                Ans[i][j] = temp->val;
                temp = temp->next;
                i--;
            }
            
            tl++;
            tr--;
            br--;
            bl++;
            
        }
        return Ans;
    }
};