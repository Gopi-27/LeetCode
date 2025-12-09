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
    TreeNode* InOrderSucc(TreeNode* root){
        if(!root->left)return root;
        return InOrderSucc(root->left);
    }
    TreeNode* DeleteNode(TreeNode* root,int key){
        if(!root)return root;
        if(root->val > key){
            root->left = DeleteNode(root->left,key);
            return root;
        }
        if(root->val < key){
            root->right = DeleteNode(root->right,key);
            return root;
        }
        if(!root->left && !root->right){
            // delete root;
            return NULL;
        }
        if(!root->right){
            TreeNode* temp = root->left;
            // delete root;
            return temp;
        }
        if(!root->left){
            TreeNode* temp = root->right;
            // delete root;
            return temp;
        }
        TreeNode* temp = InOrderSucc(root->right);
        root->val = temp->val;
        root->right = DeleteNode(root->right,temp->val);
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)return root;
        root->left = trimBST(root->left,low,high);
        root->right = trimBST(root->right,low,high);
        cout << root->val << " ";
        if(root->val < low || root->val > high)
            return DeleteNode(root,root->val);
        return root;
    }
};