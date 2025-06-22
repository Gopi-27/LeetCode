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
    void Solve(TreeNode* root,int rem,int* sum){
        if(root == NULL)return;
        (rem) = ((rem) * 2 )+ root->val;
        Solve(root->left,rem,sum);
        Solve(root->right,rem,sum);
        if(root->left == NULL && root->right == NULL)(*sum) += (rem);
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        int rem = 0;
        int sum = 0;
        Solve(root,rem,&sum);
        return sum;
    }
};