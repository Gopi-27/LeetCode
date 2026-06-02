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
    TreeNode* acc;
    bool LCA(TreeNode* root,int start,int dest){
        if(!root)return 0;
        int flag = 0;
        flag += LCA(root->left,start,dest);
        flag += LCA(root->right,start,dest);
        if(root->val == start || root->val == dest)flag++;
        if(flag == 2){
            acc = root;
            return 0;
        }
        if(flag)return 1;
        return 0;
    }
    string sstr;
    void rec(TreeNode* root,int key,string& path){
        if(!root)return;
        if(root->val == key){
            sstr = path;
            return;
        }
        path += 'L';
        rec(root->left,key,path);
        path.pop_back();
        path += 'R';
        rec(root->right,key,path);
        path.pop_back();
        return;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        LCA(root,startValue,destValue);
        string path = "";
        string ans = "";
        rec(acc,startValue,path);
        ans += sstr;
        for(int i = 0; i < ans.size(); i++)ans[i] = 'U';
        rec(acc,destValue,path);
        ans += sstr;
        cout << sstr << endl;
        cout << acc->val;
        return ans;
    }
};