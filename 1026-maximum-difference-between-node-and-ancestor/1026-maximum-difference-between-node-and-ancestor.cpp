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
    int ans = 0;
    pair<int,int> rec(TreeNode* root){
        pair<int,int> temp = {root->val,root->val};
        if(!root->left && !root->right)return temp;
        if(root->left){
            pair<int,int>l = rec(root->left);
            ans = max(ans,abs(l.first - root->val));
            ans = max(ans,abs(l.second - root->val));
            temp.first = min(temp.first,l.first);
            temp.second = max(temp.second,l.second);
        }

        if(root->right){
            pair<int,int>r = rec(root->right);
            ans = max(ans,abs(r.first - root->val));
            ans = max(ans,abs(r.second - root->val));
            temp.first = min(temp.first,r.first);
            temp.second = max(temp.second,r.second);
        }

        return temp;
    }
    int maxAncestorDiff(TreeNode* root) {
        rec(root);
        return ans;
    }
};