/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void rec(int l,Node* root, vector<Node*>& Level){
        if(!root)return;
        if(Level.size() >= l + 1){
            Level[l]->next = root;
            Level[l] = root;
        }else Level.push_back(root);
        rec(l + 1,root->left,Level);
        rec(l + 1,root->right,Level);
        return;
    }
    Node* connect(Node* root) {
        vector<Node*>Level;
        rec(0,root,Level);
        return root;
    }
};