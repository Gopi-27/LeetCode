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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>freq;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            long long sum = 0;
            int n = Q.size();
            for(int i = 0; i < n; i++){
                TreeNode* cur = Q.front();Q.pop();
                sum += cur->val;
                if(cur->left)Q.push(cur->left);
                if(cur->right)Q.push(cur->right);
            }
            freq.push_back(sum);
        }
        sort(freq.begin(),freq.end(),greater<long long>());
        if(k > freq.size())return -1;
        return freq[k - 1];
    }
};