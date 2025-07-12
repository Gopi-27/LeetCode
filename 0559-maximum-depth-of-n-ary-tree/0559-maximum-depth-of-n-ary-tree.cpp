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
    void GetHeight(Node* root,int level,int* ans){
        if(root == NULL)return;
        level++;
        *ans = max(level,(*ans));
        for(int i = 0; i < root->children.size(); i++){
            GetHeight(root->children[i],level,ans);
        }
        return;
    }
    int maxDepth(Node* root) {
        if(root == NULL)return 0;
        int level = 0;
        int ans = 0;
        GetHeight(root,level,&ans);
        return ans;
    }
};