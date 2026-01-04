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
    pair<int,int> GetValue(string& s,int idx){
        int n = s.size();
        int val = 0;
        while(idx < n && s[idx] != '-'){
            int rem = s[idx] - '0';
            val = (val * 10) + rem;
            idx++;
        }
        return {val,idx};
    }
    pair<int,int> GetDashes(string& s,int idx){
        int n = s.size();
        int cnt = 0;
        while(idx < n && s[idx] == '-'){
            cnt++;
            idx++;
        }
        return {cnt,idx};
    }
    TreeNode* recoverFromPreorder(string s) {
        stack<pair<TreeNode*,int>>st;
        int n = s.size();
        pair<int,int>d = GetDashes(s,0);
        pair<int,int>v = GetValue(s,d.second);
        TreeNode* root = new TreeNode(v.first);
        st.push({root,0});
        cout << v.second << endl;
        while(v.second < n){
            
            d = GetDashes(s,v.second);
            v = GetValue(s,d.second);

            cout << v.second << endl;

            while(st.top().second + 1 != d.first)st.pop();
            
            pair<TreeNode*,int> r = st.top();
            TreeNode* temp = new TreeNode(v.first);

            if(r.first->left)r.first->right = temp;
            else r.first->left = temp;  
            st.push({temp,d.first});
        }
        return root;
    }
};