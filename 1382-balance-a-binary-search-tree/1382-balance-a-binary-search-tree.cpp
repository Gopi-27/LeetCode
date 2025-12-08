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
    void InOrd(TreeNode* root,vector<int>&A){
        if(!root)return;
        InOrd(root->left,A);
        A.push_back(root->val);
        InOrd(root->right,A);
        return;
    }
    TreeNode* Construct(int low,int high,vector<int>& A){
        if(low > high)return NULL;
        int mid = (low + high) >> 1;
        TreeNode* temp = new TreeNode(A[mid]);
        temp->left = Construct(low,mid - 1,A);
        temp->right = Construct(mid + 1,high,A);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>tree;
        InOrd(root,tree);
        return Construct(0,tree.size() - 1,tree);
    }
};