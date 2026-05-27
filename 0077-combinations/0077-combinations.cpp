class Solution {
public:
    void rec(int val,vector<int>& comb,vector<vector<int>>& Ans,int k,int n){
        if(comb.size() > k)return;
        if(val > n){
            if(comb.size() == k)Ans.push_back(comb);
            return;
        }
        rec(val + 1,comb,Ans,k,n);
        comb.push_back(val);
        rec(val + 1,comb,Ans,k,n);
        comb.pop_back();
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>comb;
        vector<vector<int>>Ans;
        rec(1,comb,Ans,k,n);
        return Ans;
    }
};