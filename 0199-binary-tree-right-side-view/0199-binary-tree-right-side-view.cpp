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
    void rec(TreeNode* root,vector<bool>&Memo,vector<int>& rview,int level){
        if(!root)return ;
        if(!Memo[level]){
            rview.push_back(root->val);
            Memo[level] = 1;
        }
        rec(root->right,Memo,rview,level + 1);
        rec(root->left,Memo,rview,level + 1);
        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<bool>Memo(101);
        vector<int>rview;
        rec(root,Memo,rview,0);
        return rview;
    }
};