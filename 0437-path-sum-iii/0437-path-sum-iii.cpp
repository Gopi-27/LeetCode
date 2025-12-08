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
    int ans = 0;
    void rec(TreeNode* root,vector<int>& A,int key,long long& sum){
        if(!root)return;
        A.push_back(root->val);
        sum += root->val;
        long long suff = sum;
        for(int i = 0; i < A.size(); i++){
            if(suff == key){
                ans++;
            }
            suff -= A[i];
            
        }
        rec(root->left,A,key,sum);
        rec(root->right,A,key,sum);
        A.pop_back();
        sum -= root->val;
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>A;
        long long sum = 0;
        rec(root,A,targetSum,sum);
        return ans;
    }
};