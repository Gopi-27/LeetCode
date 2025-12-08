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
    void rec(TreeNode* root,int mask,int& cnt){
        if(!root)return;
        mask ^= (1 << (root->val - 1));
        rec(root->left,mask,cnt);
        rec(root->right,mask,cnt);
        if(!root->left && !root->right){
            if(mask == 0 || (mask & (mask - 1)) == 0)cnt++;
        }
        return ;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        int mask = 0;
        rec(root,mask,cnt);
        return cnt;
    }
};