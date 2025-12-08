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
    bool rec(TreeNode* root,long long& prev){
        if(!root)return true;
        bool flag1 = rec(root->left,prev);
        if(prev >= root->val)return false;
        prev = root->val;
        bool flag2 = rec(root->right,prev);
        return flag1 && flag2;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN;
        return rec(root,prev);        
    }
};