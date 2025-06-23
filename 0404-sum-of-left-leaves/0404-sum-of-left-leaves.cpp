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
    void Solve(TreeNode* root,int* sum,bool flag){
        if(root == NULL)return;
        Solve(root->left,sum,1);
        if(flag && root->left == NULL && root->right == NULL)(*sum) += root->val;
        Solve(root->right,sum,0);
        return;

    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        Solve(root,&sum,0);
        return sum;
    }
};