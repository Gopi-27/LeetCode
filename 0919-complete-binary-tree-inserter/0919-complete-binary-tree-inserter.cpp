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
class CBTInserter {
private:
    TreeNode* myroot;
    queue<TreeNode*>myQ;
public:
    CBTInserter(TreeNode* root) {
        myroot = new TreeNode(root->val);
        myQ.push(myroot);
        queue<TreeNode*>Q;
        if(root->left)Q.push(root->left);
        if(root->right)Q.push(root->right);
        while(!Q.empty()){
                TreeNode* curr = Q.front();Q.pop();
                if(curr->left)Q.push(curr->left);
                if(curr->right)Q.push(curr->right);

                TreeNode* mycurr = myQ.front();
                cout << curr->val << " " << mycurr->val << endl;
                if(!mycurr->left){
                    TreeNode* myleft = new TreeNode(curr->val);
                    mycurr->left = myleft;
                    myQ.push(myleft);
                }else{
                    TreeNode* myright = new TreeNode(curr->val);
                    mycurr->right = myright;
                    myQ.push(myright);
                    myQ.pop();
                }
            
        }
        
    }
    
    int insert(int val) {
        TreeNode* curr = myQ.front();
        if(!curr->left){
            TreeNode* myleft = new TreeNode(val);
            curr->left = myleft;
            myQ.push(myleft);
            return curr->val;
        }else{
            TreeNode* myright = new TreeNode(val);
            curr->right = myright;
            myQ.push(myright);
            myQ.pop();
            return curr->val;
        }
    }
    
    TreeNode* get_root() {
        return myroot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */