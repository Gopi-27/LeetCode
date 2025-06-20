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
    bool DFS(TreeNode* root){
        if(root == NULL)return false;
        bool flag1 = DFS(root->left);
        if(!flag1)root->left = NULL;
        bool flag2 = DFS(root->right);
        if(!flag2)root->right = NULL;
        if(flag1 || flag2 || root->val)return true;
        return false;            
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool flag = DFS(root);
        if(flag || root->val)return root;
        return NULL;
    }
};