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
    Node* connect(Node* root) {
        if(root == NULL)return root;
        queue<Node*>Q;
        Q.push(root);
        while(!Q.empty()){
            int n = Q.size();
            Node* prev = Q.front();Q.pop();
            if(prev->left)Q.push(prev->left);
            if(prev->right)Q.push(prev->right);
            for(int i = 0; i < n - 1; i++){
                Node* curr = Q.front();Q.pop();
                if(curr->left)Q.push(curr->left);
                if(curr->right)Q.push(curr->right);
                prev->next = curr;
                prev = curr;
            }
        }
        return root;
    }
};