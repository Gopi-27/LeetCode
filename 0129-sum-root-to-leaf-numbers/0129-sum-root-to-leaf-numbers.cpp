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
    void DFS(TreeNode* root,int &num,int & ans){
        if(root == NULL)return;
        num = (num * 10) + root->val;
        DFS(root->left,num,ans);
        DFS(root->right,num,ans);
        if(root->left == NULL && root->right == NULL)ans += num;
        num /= 10;
        return;
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int num = 0;
        DFS(root,num,ans);
        return ans;
    }
};