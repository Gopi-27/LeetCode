/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    bool rec(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root)return 0;
        bool l = rec(root->left,p,q);
        bool r = rec(root->right,p,q);
        bool rflag = 0;
        if(root == p || root == q)rflag = 1;
        if((l && r) || (l && rflag) || (r && rflag)){
            ans = root;
            return 0;
        }
        return l | r | rflag;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rec(root,p,q);
        return ans;

    }
};