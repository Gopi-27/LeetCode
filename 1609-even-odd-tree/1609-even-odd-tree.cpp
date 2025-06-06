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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>Q;
        Q.push(root);
        int level = -1;
        while(!Q.empty()){
            level++;
            int n = Q.size();
            TreeNode* Prev = Q.front();
            Q.pop();
            if(level & 1){
                if(Prev->val & 1)return false;
                if(Prev->left)Q.push(Prev->left);
                if(Prev->right)Q.push(Prev->right);
                for(int i = 1; i < n; i++){
                    TreeNode* Cur = Q.front();
                    Q.pop();
                    if(Cur->val & 1 || Prev->val <= Cur->val )return false;
                    if(Cur->left)Q.push(Cur->left);
                    if(Cur->right)Q.push(Cur->right);
                    Prev = Cur;
                }
            }else{
                if(!(Prev->val & 1))return false;
                if(Prev->left)Q.push(Prev->left);
                if(Prev->right)Q.push(Prev->right);
                for(int i = 1; i < n; i++){
                    TreeNode* Cur = Q.front();
                    Q.pop();
                    if(!(Cur->val & 1) || Prev->val >= Cur->val )return false;
                    if(Cur->left)Q.push(Cur->left);
                    if(Cur->right)Q.push(Cur->right);
                    Prev = Cur;
                }
            }
            
        }
        return true;
    }
};