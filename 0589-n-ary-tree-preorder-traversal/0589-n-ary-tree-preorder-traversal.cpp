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
    vector<int> preorder(Node* root) {
        vector<int>Ans;
        if(root == NULL)return Ans;
        stack<Node*>mystack;
        mystack.push(root);
        while(!mystack.empty()){
            Node* Cur = mystack.top();
            Ans.push_back(Cur->val);
            mystack.pop();
            int n = Cur->children.size();
            for(int i = n - 1; i >=0; i--){
                mystack.push(Cur->children[i]);
            }
        }
        return Ans;
    }
};