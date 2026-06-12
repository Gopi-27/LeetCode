class TreeAncestor {
public:
    vector<vector<int>>Par;
    TreeAncestor(int n, vector<int>& parent) {
        Par.resize(n);
        for(int i = 0; i < n; i++)Par[i].resize(20);
        for(int i = 0; i < n; i++)Par[i][0] = parent[i];
        for(int j = 1; j < 20; j++){
            for(int i = 0; i < n; i++){
                if(Par[i][j - 1] == -1)Par[i][j] = -1;
                else Par[i][j] = Par[Par[i][j - 1]][j - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int bin = 0;
        while(k > 0){
            if(node == -1)return node;
            if(k & 1)node = Par[node][bin];
            k >>= 1;
            bin++;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */