/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Reverse(deque<TreeNode*>dq){
        int n = dq.size();
        for(int i = 0; i < n / 2; i++){
            swap(dq[i]->val,dq[n - i - 1]->val); 
        }
        return;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        deque<TreeNode*>dq;
        dq.push_back(root);
        int level = -1;

        while(!dq.empty()){
            level++;
            if(level % 2)Reverse(dq);
            int n = dq.size();
            for(int i = 0; i < n; i++){
                TreeNode* Cur = dq.front();
                dq.pop_front();
                if(Cur->left)dq.push_back(Cur->left);
                if(Cur->right)dq.push_back(Cur->right);
            }
        }
        return root;
    }
};