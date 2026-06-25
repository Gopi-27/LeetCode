class LUPrefix {
public:
    vector<int>Par;
    vector<bool>Vis;
    LUPrefix(int n) {
        Par.resize(n + 2);
        Vis.resize(n + 2);
        for(int i = 1; i <= n; i++)Par[i] = i;
        Vis[0] = 1;
    }
    int findPar(int u){
        if(Par[u] == u)return u;
        return Par[u] = findPar(Par[u]);
    }
    void Union(int u,int v){
        int up = findPar(u);
        int vp = findPar(v);
        if(up < vp)Par[up] = vp;
        else Par[vp] = up;
    }
    void upload(int video) {
        if(Vis[video - 1])Union(video - 1,video);
        if(Vis[video + 1])Union(video,video + 1);
        Vis[video] = 1;
    }
    
    int longest() {
        return findPar(0);
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */