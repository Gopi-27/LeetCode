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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        int di = 1;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int n = Q.size();
            vector<int>temp(n);
            int i;
            if(di == 1)i = 0;
            else i = n - 1;
            for(int k = 0; k < n; k++){
                TreeNode* cur = Q.front();Q.pop();
                temp[i] = cur->val;
                if(cur->left)Q.push(cur->left);
                if(cur->right)Q.push(cur->right);
                i += di;
            }
            ans.push_back(temp);
            if(di == 1)di = -1;
            else di = 1;
        }
        return ans;
    }
};