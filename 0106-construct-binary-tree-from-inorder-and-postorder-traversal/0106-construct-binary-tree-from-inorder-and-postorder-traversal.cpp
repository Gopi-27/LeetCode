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
    int GetIdx(vector<int>& A,int low,int high,int key){
        for(int i = low; i <= high; i++){
            if(A[i] == key)return i;
        }
        return 0;
    }
    TreeNode* rec(vector<int>& in,vector<int>& post,int& i,int low,int high){
        if(low > high)return NULL;
        int idx = GetIdx(in,low,high,post[i]);
        TreeNode* root = new TreeNode(post[i]);
        i--;
        root->right = rec(in,post,i,idx + 1,high);
        root->left = rec(in,post,i,low,idx - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size() - 1;
        return rec(inorder,postorder,i,0,i);
    }
};