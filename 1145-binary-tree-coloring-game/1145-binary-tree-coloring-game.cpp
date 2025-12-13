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
    TreeNode* rec(TreeNode* root,int x){
        if(!root)return NULL;
        if(root->val == x)return root;
        TreeNode* l = rec(root->left,x);
        if(l)return l;
        return rec(root->right,x);
    }
    int CntNodes(TreeNode* root){
        if(!root)return 0;
        int l = CntNodes(root->left);
        int r = CntNodes(root->right);
        return l + r + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* red = rec(root,x);
        int l = CntNodes(red->left);
        int r = CntNodes(red->right);
        int p = n - l - r - 1;
        cout << p << " " << l <<" " << r;
        if(p > (l + r + 1))return true;
        if(l > (p + r + 1))return true;
        if(r > (p + l + 1))return true;
        return false;
    }
};