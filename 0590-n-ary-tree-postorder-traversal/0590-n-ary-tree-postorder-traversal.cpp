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
    void DFS(Node* root,vector<int>& Ans){
        if(root == NULL)return;
        int n = root->children.size();
        for(int i = 0; i < n; i++){
            DFS(root->children[i],Ans);
        }
        Ans.push_back(root->val);
        return;

    }
    vector<int> postorder(Node* root) {
        vector<int>Ans;
        DFS(root,Ans);
        return Ans;
    }
};