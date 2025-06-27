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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            sum = 0;
            int n = Q.size();
            for(int i = 0; i < n; i++){
                TreeNode* Cur = Q.front();
                Q.pop();
                sum += Cur->val;
                if(Cur->left)Q.push(Cur->left);
                if(Cur->right)Q.push(Cur->right);
            }
        }
        return sum;
    }
};