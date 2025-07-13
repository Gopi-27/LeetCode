class Solution {
public:
    bool DFS(int cur,int n,vector<int>& Ans){
        if(cur > n)return 1;
        Ans.push_back(cur);
        for(int i = 0; i < 10; i++){
            if(DFS(cur * 10 + i,n,Ans))break;
        }
        return 0;
    }
    vector<int> lexicalOrder(int n) {
        vector<int>Ans;
        for(int i = 1; i < 10; i++){
            if(DFS(i,n,Ans))break;
        }
        return Ans;
    }
};