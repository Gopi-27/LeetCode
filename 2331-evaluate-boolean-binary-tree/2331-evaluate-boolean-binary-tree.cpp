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
    void DFS(TreeNode* root){
        if(root == NULL)return;
        DFS(root->left);
        DFS(root->right);

        if(root->val == 1)return;
        if(root->val == 0)return;

        if(root->val == 2)root->val = root->left->val | root->right->val;
        else root->val = root->left->val & root->right->val;
        return;
    }
    bool evaluateTree(TreeNode* root) {
        DFS(root);
        return root->val;
    }
};