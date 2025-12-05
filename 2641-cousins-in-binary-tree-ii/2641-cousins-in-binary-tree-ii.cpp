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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>Q;
        Q.push(root);
        int sum = root->val;
        while(!Q.empty()){
            int n = Q.size();
            int newsum = 0;
            for(int i = 0; i < n; i++){
                TreeNode* Cur = Q.front();
                Q.pop();
                Cur->val = sum - Cur->val;
                if(Cur->left && Cur->right){
                    Cur->left->val += Cur->right->val;
                    Cur->right->val = Cur->left->val;
                }
                if(Cur->left)Q.push(Cur->left);
                if(Cur->right)Q.push(Cur->right);
                
                if(Cur->left)newsum += Cur->left->val;
                else if(Cur->right)newsum += Cur->right->val;
            }
            sum = newsum;
        }
        return root;
    }
};