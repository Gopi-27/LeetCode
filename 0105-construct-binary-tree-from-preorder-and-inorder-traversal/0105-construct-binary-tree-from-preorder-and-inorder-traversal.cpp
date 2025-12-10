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
        //
        return 0;
    }
    TreeNode* rec(vector<int>& pre,vector<int>& in,int& i,int low,int high){
        if(low > high)return NULL;
        int idx = GetIdx(in,low,high,pre[i]);
        TreeNode* root = new TreeNode(pre[i]);
        i++;
        root->left = rec(pre,in,i,low, idx - 1);
        root->right = rec(pre,in,i,idx + 1,high);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return rec(preorder,inorder,i,0,preorder.size() - 1);
    }
};