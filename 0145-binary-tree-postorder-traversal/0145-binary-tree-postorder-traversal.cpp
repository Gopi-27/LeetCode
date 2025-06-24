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
    vector<int> postorderTraversal(TreeNode* root) {
        // root - right - left (reverse)
        vector<int>Ans;
        if(root == NULL)return Ans;
        stack<TreeNode*>mystack;
        mystack.push(root);
        while(!mystack.empty()){
            TreeNode* Cur = mystack.top();
            mystack.pop();
            Ans.push_back(Cur->val);
            if(Cur->left)mystack.push(Cur->left);
            if(Cur->right)mystack.push(Cur->right);
        }
        reverse(Ans.begin(),Ans.end());
        return Ans;
    }
};