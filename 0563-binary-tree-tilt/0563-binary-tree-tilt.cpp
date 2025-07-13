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
    int DFS(TreeNode* root,int *sum){
        if(root == NULL)return 0;
        int lsum = DFS(root->left,sum);
        int rsum = DFS(root->right,sum);
        (*sum) += abs(lsum - rsum);
        return lsum + rsum + root->val;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        int temp = DFS(root ,&sum);
        return sum;        
    }
};