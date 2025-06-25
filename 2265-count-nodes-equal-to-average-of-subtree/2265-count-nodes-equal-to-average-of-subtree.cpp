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
    pair<int,int> DFS(TreeNode* root,int* Ans){
        if(root == NULL)return {0,0};
        pair<int,int>leftpair = DFS(root->left,Ans);
        pair<int,int>rightpair = DFS(root->right,Ans);
        int sum = leftpair.first + rightpair.first + root->val;
        int cnt = leftpair.second + rightpair.second + 1;
        if(sum/cnt == root->val)(*Ans)++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int Ans = 0;
        pair<int,int>temp = DFS(root,&Ans);
        return Ans;
    }
};