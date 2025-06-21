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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)return {};
        stack<TreeNode*>mystack;
        mystack.push(root);
        vector<int>Ans;
        while(!mystack.empty()){
            TreeNode* CurNode = mystack.top();
            mystack.pop();
            Ans.push_back(CurNode->val);
            if(CurNode->right)mystack.push(CurNode->right);
            if(CurNode->left)mystack.push(CurNode->left);
        }
        return Ans;
    }
};