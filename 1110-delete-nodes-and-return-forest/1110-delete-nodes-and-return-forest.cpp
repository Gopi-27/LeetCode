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
    bool Found(int key,vector<int>& A){
        int low = 0;
        int high = A.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(A[mid] == key)return true;
            else if(A[mid] < key)low = mid + 1;
            else high = mid - 1;
        }
        return 0;
    }
    TreeNode* rec(TreeNode* root,vector<int>& to_delete,vector<TreeNode*>& ans){
        if(!root)return NULL;
        root->left = rec(root->left,to_delete,ans);
        root->right = rec(root->right,to_delete,ans);
        if(Found(root->val,to_delete)){
            if(root->left)ans.push_back(root->left);
            if(root->right)ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(to_delete.begin(),to_delete.end());
        vector<TreeNode*>ans;
        TreeNode* temp = rec(root,to_delete,ans);
        if(temp)ans.push_back(temp);
        return ans;
    }
};