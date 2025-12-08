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
class BSTIterator {
private:
    vector<int>A;
    int idx = 0;
public:
    void InOrder(TreeNode* root){
        if(!root)return;
        InOrder(root->left);
        A.push_back(root->val);
        InOrder(root->right);
        return;
    }
    BSTIterator(TreeNode* root) {
       InOrder(root); 
    }
    int next() {
       return A[idx++]; 
    }
    
    bool hasNext() {
        return idx < A.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */