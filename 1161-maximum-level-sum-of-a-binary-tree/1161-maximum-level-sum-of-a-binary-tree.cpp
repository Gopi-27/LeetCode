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
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        queue<TreeNode*>Q;
        Q.push(root);
        int oldsum = root->val;
        int maxi = oldsum;
        int level = 0;
        while(!Q.empty()){
            level++;
            if(maxi < oldsum){
                maxi = oldsum;
                ans = level;
            }
            int newsum = 0;
            int n = Q.size();
            for(int i = 0; i < n; i++){
                TreeNode* cur = Q.front();
                Q.pop();
                if(cur->left){
                    newsum += cur->left->val;
                    Q.push(cur->left);
                }
                if(cur->right){
                    newsum += cur->right->val;
                    Q.push(cur->right);
                }
            }
            oldsum = newsum;
        }
        return ans;
    }
};