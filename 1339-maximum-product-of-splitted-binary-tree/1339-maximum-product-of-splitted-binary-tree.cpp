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
    long long ans = LLONG_MIN;
    int mod = 1e9 + 7;
    int GetSum(TreeNode* root){
        if(!root)return 0;
        int l = GetSum(root->left);
        int r = GetSum(root->right);
        return root->val + l + r;
    }
    int rec(TreeNode* root,int sum){
        if(!root)return 0;
        int l = rec(root->left,sum);
        int r = rec(root->right,sum);
        int val = root->val + l + r;
        ans = max(ans,1ll * (sum - val) * (val));
        return val;
    }
    int maxProduct(TreeNode* root){
        int sum = GetSum(root);
        rec(root,sum);
        ans %= mod;
        return ans;
    }
};