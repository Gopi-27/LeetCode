class Node {
public:
    string web;
    Node* prev;
    Node* next;
    Node(string w = "",Node* p = NULL,Node* n = NULL){
        web = w;
        prev = p;
        next = n;
    }
};
class BrowserHistory {
public:
    Node* head;
    BrowserHistory(string homepage) {
        head = new Node(homepage);
    } 
    void visit(string url) {
        Node* temp = new Node(url,head);
        head->next = temp;
        head = temp;
    }
    
    string back(int steps) {
        while(head->prev && steps--)head = head->prev;        
        return head->web;
    }
    
    string forward(int steps) {
        while(head->next && steps--)head = head->next;
        return head->web;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */