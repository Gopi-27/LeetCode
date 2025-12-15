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
    int ans = INT_MIN;
    int rec(TreeNode* root){
        if(!root)return 0;
        int l = rec(root->left);
        int r = rec(root->right);
        ans = max(ans,l + r + root->val);
        int temp = max(l + root->val,r + root->val);
        temp = max(root->val,temp);
        ans = max(temp,ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        rec(root);
        return ans;
    }
};