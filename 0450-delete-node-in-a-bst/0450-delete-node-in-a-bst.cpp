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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val > key){
            root->left = deleteNode(root->left,key);
            return root;
        }
        if(root->val < key){
            root->right = deleteNode(root->right,key);
            return root;
        }
        // no/one/two => childs
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        if(!root->left && root->right){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left && !root->right){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = InOrderSucc(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right,temp->val);
        return root;
    }
};