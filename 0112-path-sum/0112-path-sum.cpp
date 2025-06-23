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
    void Solve(TreeNode* root,bool* flag,int targetSum,int sum){
        if((*flag) || root == NULL)return;
        sum += root->val;
        Solve(root->left,flag,targetSum,sum);
        Solve(root->right,flag,targetSum,sum);
        if(root->left == NULL && root->right == NULL && targetSum == sum)(*flag) = 1;
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = 0;
        Solve(root,&flag,targetSum,0);
        return flag;
    }
};





