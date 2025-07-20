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
    void DFS(TreeNode* root,vector<vector<int>>& Ans,vector<int>& path,int & sum,int & targetSum){      
        if(root == NULL)return;
        path.push_back(root->val);
        sum += root->val;
        DFS(root->left,Ans,path,sum,targetSum);
        DFS(root->right,Ans,path,sum,targetSum);
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum)Ans.push_back(path);
        }
        sum -= root->val;
        path.pop_back();
        return;   
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return{};
        vector<vector<int>> Ans;
        vector<int>path;
        int sum = 0;
        DFS(root,Ans,path,sum,targetSum);
        return Ans;
    }
};