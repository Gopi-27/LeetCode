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
        if(!root)return {-2000,0};
        pair<int,int> l = rec(root->left);
        pair<int,int> r = rec(root->right);
        pair<int,int> temp = {root->val,0};
        if(l.first == root->val && r.first == root->val){
           ans = max(ans,l.second + r.second + 1); 
           temp.second = max(l.second + 1,r.second + 1);
        }
        else if(l.first == root->val){
            temp.second = l.second + 1;
            ans = max(ans,temp.second);
        }else if(r.first == root->val){
            temp.second = r.second + 1;
            ans = max(ans,temp.second);
        }else{
            temp.second = 1;
            ans = max(ans,temp.second);
        }
        return temp;
        
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        rec(root);
        return ans - 1;
    }
};