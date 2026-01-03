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
    void rec(TreeNode* root,int row,int col,map<int,map<int,vector<int>>>& mpp){
        if(!root)return;
        mpp[col][row].push_back(root->val);
        rec(root->left,row + 1,col - 1,mpp);
        rec(root->right,row + 1,col + 1,mpp);
        return ;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mpp;
        rec(root,0,0,mpp);
        vector<vector<int>>ans;
        for(auto b : mpp){
            vector<int>col;
            for(auto v : b.second){
                sort(v.second.begin(),v.second.end());
                for(auto ele : v.second)col.push_back(ele);
            }
            ans.push_back(col);
        }
        return ans;
    }
};