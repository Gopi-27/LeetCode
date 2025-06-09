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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)return true;
    if(p == NULL)return false;
    if(q == NULL)return false;
    if(p->val != q->val)return false;
    queue<TreeNode*>pQ;
    queue<TreeNode*>qQ;
    pQ.push(p);
    qQ.push(q);
    while(!pQ.empty() && !qQ.empty()){
        int n = pQ.size();
        for(int i = 0; i < n; i++){
            TreeNode* curp = pQ.front();pQ.pop();
            TreeNode* curq = qQ.front();qQ.pop();
            if((curp->left == NULL && curq->left != NULL) || (curp->left != NULL && curq->left == NULL))
            return false;

            if((curp->right == NULL && curq->right != NULL) || (curp->right != NULL && curq->right == NULL))
            return false;

            if(curp->left){
                if(curp->left->val != curq->left->val)return false;
                pQ.push(curp->left);
                qQ.push(curq->left);
            }

            if(curp->right){
                if(curp->right->val != curq->right->val)return false;
                pQ.push(curp->right);
                qQ.push(curq->right);
            }


        }
        
    } 
    return true;
    }
};