/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        queue<Node*>Q;
        Q.push(root);
        while(!Q.empty()){
            int n = Q.size();
            vector<int>temp;
            for(int i = 0; i < n; i++){
                Node* curr = Q.front();Q.pop();
                temp.push_back(curr->val);
                for(auto n : curr->children)Q.push(n);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};