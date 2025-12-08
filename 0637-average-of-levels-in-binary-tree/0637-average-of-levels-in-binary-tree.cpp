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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int n = Q.size();
            double sum = 0;
            for(int i = 0; i < n; i++){
                TreeNode* curr = Q.front();Q.pop();
                sum += curr->val;
                if(curr->left)Q.push(curr->left);
                if(curr->right)Q.push(curr->right);
            }
            ans.push_back(sum/n);
        }
        return ans;
    }
};