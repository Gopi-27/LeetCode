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
    void rec(TreeNode* root,int parent,int grandparent,int& sum){
        if(root == NULL)return;
        if(grandparent % 2 == 0)sum += root->val;
        rec(root->left,root->val,parent,sum);
        rec(root->right,root->val,parent,sum);
        return;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;
        rec(root,1,1,ans);
        return ans;
    }
};