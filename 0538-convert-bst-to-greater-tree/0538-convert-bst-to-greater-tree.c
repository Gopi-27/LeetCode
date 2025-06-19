/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void Solve(struct TreeNode* root,int* ptr){
    if(root == NULL)return ;
    Solve(root->right,ptr);
    (*ptr) += root->val;
    root->val = (*ptr);
    Solve(root->left,ptr);
    return;
}
struct TreeNode* convertBST(struct TreeNode* root) {
    int sum = 0;
    Solve(root,&sum);
    return root;
}