/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void Divide(struct TreeNode* root,int low, int high,int* sum){
    if(root==NULL){
        return ;
    }

    if((root->val)>=low && (root->val)<=high)(*sum)+=root->val;

    struct TreeNode *LEFT=root->left;
    Divide(LEFT,low,high,sum);
    struct TreeNode *RIGHT=root->right;
    Divide(RIGHT,low,high,sum);
    return;
}

int rangeSumBST(struct TreeNode* root, int low, int high) {
    int sum=0;
    Divide(root,low,high,&sum);
    return sum;
   

}