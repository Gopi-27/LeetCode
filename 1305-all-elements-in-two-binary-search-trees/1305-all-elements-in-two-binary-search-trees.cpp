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
    void InOrder(TreeNode* root,vector<int>& A){
        if(!root)return;
        InOrder(root->left,A);
        A.push_back(root->val);
        InOrder(root->right,A);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>A;
        InOrder(root1,A);
        vector<int>B;
        InOrder(root2,B);
        vector<int>C;
        int i = 0;
        int j = 0;
        while(i < A.size() && j < B.size()){
            if(A[i] >= B[j])C.push_back(B[j++]);
            else C.push_back(A[i++]);
            
        }
        while(i < A.size())
            C.push_back(A[i++]);
        while(j < B.size())
            C.push_back(B[j++]);
        return C;
        
    }
};