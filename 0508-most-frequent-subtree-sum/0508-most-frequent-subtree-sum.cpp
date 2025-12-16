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
    unordered_map<int,int> mpp;
    int max_freq = 0;
    vector<int>ans;
    int rec(TreeNode* root){
        if(!root)return 0;
        int l = rec(root->left);
        int r = rec(root->right);
        int cur = l + r + root->val;
        mpp[cur]++;
        if(mpp[cur] > max_freq){
            max_freq = mpp[cur];
            ans.clear();
            ans.emplace_back(cur);
        }else if(mpp[cur] == max_freq)ans.emplace_back(cur);
        return cur;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        rec(root);
        return ans;
    }
};