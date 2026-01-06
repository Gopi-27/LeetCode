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
    TreeNode* ans;
    int rec(TreeNode* root,vector<int>& nodes){
        if(!root)return 0;
        int l = rec(root->left,nodes);
        int r = rec(root->right,nodes);
        if(find(nodes.begin(),nodes.end(),root->val) != nodes.end())l++;
        if(l + r == nodes.size()){
            ans = root;
            return l + r + 5;
        }
        return l + r; 
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<int>llevel;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int n = Q.size();
            llevel.clear();
            for(int i = 0; i < n; i++){
                TreeNode* cur = Q.front();Q.pop();
                llevel.push_back(cur->val);
                if(cur->left)Q.push(cur->left);
                if(cur->right)Q.push(cur->right);
            }
        }
        rec(root,llevel);
        return ans;
    }
};