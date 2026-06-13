/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        map<int,Node*>Adj;

        queue<Node*>Q;
        Q.push(node);
        Adj[node->val] = new Node(node->val);

        while(!Q.empty()){
            Node* u = Q.front();Q.pop();
            for(auto& v : u->neighbors){
                if(!Adj.count(v->val)){
                    Adj[v->val] = new Node(v->val);
                    Q.push(v);
                }
            }
        }

        set<int>st;
        st.insert(node->val);
        Q.push(node);
        while(!Q.empty()){
            Node* u = Q.front();Q.pop();
            for(auto& v : u->neighbors){
                Adj[u->val]->neighbors.push_back(Adj[v->val]);
                if(!st.count(v->val)){
                    st.insert(v->val);
                    Q.push(v);
                }
            }
        }
        return Adj[1];       
    }
};