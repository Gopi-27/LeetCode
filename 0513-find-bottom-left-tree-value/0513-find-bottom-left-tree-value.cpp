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
    void rec(TreeNode* root,int& prev_level,int level,int& ans){
        if(!root)return;
        if(level > prev_level){
            ans = root->val;
            prev_level++;
        }
        rec(root->left,prev_level,level + 1,ans);
        rec(root->right,prev_level,level + 1,ans);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        int prev_level = 0;
        rec(root,prev_level,1,ans);
        return ans;
    }
};