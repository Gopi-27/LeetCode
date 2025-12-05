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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* curr = new TreeNode(val);
            curr->left = root;
            return curr;
        }
        queue<TreeNode*>Q;
        Q.push(root);
        int level = 1;
        while(level < depth - 1){
            level++;
            int n = Q.size();
            for(int i = 0; i < n; i++){
                TreeNode* curr = Q.front();Q.pop();
                if(curr->left)Q.push(curr->left);
                if(curr->right)Q.push(curr->right);
            }
        }
        while(!Q.empty()){
            TreeNode* curr = Q.front();Q.pop();
            TreeNode* newleft = new TreeNode(val,curr->left,NULL);
            TreeNode* newright = new TreeNode(val,NULL,curr->right);
            curr->left = newleft;
            curr->right = newright;
        }
        return root;
    }
};