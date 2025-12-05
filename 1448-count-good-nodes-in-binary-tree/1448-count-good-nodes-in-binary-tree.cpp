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
    void rec(TreeNode* root,int maxi,int& ans){
        if(!root)return;
        if(maxi <= root->val)ans++;
        maxi = max(maxi,root->val);
        rec(root->left,maxi,ans);
        rec(root->right,maxi,ans);
        return;
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        rec(root,INT_MIN,ans);
        return ans;
    }
};