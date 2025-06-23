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
    void Solve(TreeNode* root,int* flag,int key){
        if((*flag) || root == NULL)return;
        if(root->val != key)(*flag) = 1;
        Solve(root->left,flag,key);
        Solve(root->right,flag,key);
        return;
    }
    bool isUnivalTree(TreeNode* root) {
        int flag = 0;
        Solve(root,&flag,root->val);
        return !flag;
    }
};