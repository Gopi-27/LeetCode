/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void GetDepth(struct TreeNode* root,int depth,int *ans){
    if(root == NULL)return;
    depth++;
    if(depth > (*ans))(*ans) = depth;
    GetDepth(root->left,depth,ans);
    GetDepth(root->right,depth,ans);
    return;
 }
int maxDepth(struct TreeNode* root) {
    int depth = 0;
    int ans = 0;
    GetDepth(root,depth,&ans);
    return ans;
}










