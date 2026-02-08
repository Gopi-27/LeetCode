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
    bool flag = 1;
    int rec(TreeNode* root){
        if(!root)return 0;
        int l = rec(root->left);
        int r = rec(root->right);
        if(l - r < - 1 || l - r > 1)flag = 0;
        return max(l,r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        rec(root);
        return flag;
    }
};