/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>Org_Q;
        queue<TreeNode*>Clo_Q;
        Org_Q.push(original);
        Clo_Q.push(cloned);
        while(!Org_Q.empty()){
            int n = Org_Q.size();
            for(int i = 0; i < n; i++){
                TreeNode* Cur_O = Org_Q.front();
                TreeNode* Cur_C = Clo_Q.front();
                Org_Q.pop();
                Clo_Q.pop();

                if(Cur_O == target)return Cur_C;

                if(Cur_O->left)Org_Q.push(Cur_O->left);
                if(Cur_O->right)Org_Q.push(Cur_O->right);
                if(Cur_C->left)Clo_Q.push(Cur_C->left);
                if(Cur_C->right)Clo_Q.push(Cur_C->right); 
            }
        }
        // will not come to here
        return NULL;

    }
};