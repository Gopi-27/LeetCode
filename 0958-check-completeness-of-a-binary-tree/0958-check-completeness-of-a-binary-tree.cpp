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
    bool isCompleteTree(TreeNode* root) {
        bool flag = 1;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int n = Q.size();
            for(int i = 0; i < n; i++){
                TreeNode* curr = Q.front();Q.pop();
                if(!flag && curr->left)return false;
                if(curr->left)Q.push(curr->left);
                else flag = false;
                if(!flag && curr->right)return false;
                if(curr->right)Q.push(curr->right);
                else flag = false;
            }
        }
        return true;
    }
};