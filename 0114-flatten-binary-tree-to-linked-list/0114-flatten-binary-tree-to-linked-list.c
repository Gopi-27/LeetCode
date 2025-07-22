/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void Solve(struct TreeNode* root,struct TreeNode **tail){
    if(root == NULL)return;
    struct TreeNode* lroot = root->left;
    struct TreeNode* rroot = root->right;
    root->left = NULL;
    (*tail)->right = root;
    (*tail) = root;
    Solve(lroot,tail);
    Solve(rroot,tail);
    return;
}
void flatten(struct TreeNode* root) {
    if(root == NULL)return;
    struct TreeNode* tail = root;
    struct TreeNode* lroot = root->left;
    struct TreeNode* rroot = root->right;
    tail->left = NULL;
    Solve(lroot,&tail);
    Solve(rroot,&tail);
    tail->right = NULL;
    return;
}