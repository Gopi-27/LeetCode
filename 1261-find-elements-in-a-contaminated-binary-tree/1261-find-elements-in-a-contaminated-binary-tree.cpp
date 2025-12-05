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
class FindElements {
private:
    vector<bool>Memo;
public:
    void rec(TreeNode* root){
        if(root == NULL)return;
        if(root->left){
            root->left->val = 2 * root->val + 1;
            if(root->left->val < 1000001)Memo[root->left->val] = 1;
        } 
        if(root->right){
            root->right->val = 2 * root->val + 2;
            if(root->right->val < 1000001)Memo[root->right->val] = 1;
        } 
        rec(root->left);
        rec(root->right);     
    }
    FindElements(TreeNode* root) {
        Memo.resize(1000001);
        if(root->val != 0)root->val = 0;
        Memo[0] = 1;
        rec(root);
    }
    
    bool find(int target) {
        if(target > 1000000)return false;
        return Memo[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */