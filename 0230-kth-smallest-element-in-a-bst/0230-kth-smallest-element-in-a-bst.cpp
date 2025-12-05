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
    void rec(TreeNode* root,int& cnt,int& ans,int k){
        if(!root)return ;
        rec(root->left,cnt,ans,k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        rec(root->right,cnt,ans,k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int cnt = 0;
        rec(root,cnt,ans,k);
        return ans;
    }
};