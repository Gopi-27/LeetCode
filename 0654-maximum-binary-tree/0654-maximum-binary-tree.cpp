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
    int GetMaxidx(vector<int>& A,int start,int end){
        //if(start > end)return -1;
        int maxidx = start;
        for(int i = start + 1 ; i <= end; i++){
            if(A[maxidx] < A[i])maxidx = i;
        }
        return maxidx;
    }
    TreeNode* Construction(vector<int>& A,int start,int end){
        if(start > end)return NULL;
        int maxidx = GetMaxidx(A,start,end);
        // cout << maxidx << endl;
        TreeNode* Cur = new TreeNode(A[maxidx]);
        // cout << root->val << endl;
        Cur->left = Construction(A,start,maxidx - 1);
        Cur->right = Construction(A,maxidx + 1,end);
        return Cur;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size() - 1;
        // cout << GetMaxidx(nums,0,3);
        return Construction(nums,0,n);
    
    }
};