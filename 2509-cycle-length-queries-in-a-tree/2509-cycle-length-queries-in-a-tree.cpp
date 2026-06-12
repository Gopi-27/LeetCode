class Solution {
public:
    int GetLength(int u,int v){
        int lu = log2(u);
        int lv = log2(v);
        if(lu > lv)u >>= lu - lv;
        else v >>= lv - lu;
        int ans = abs(lu - lv);
        while(u != v){
            u >>= 1;
            v >>= 1;
        }
        int h = log2(u);
        return lu + lv - 2 * h + 1;

    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>Ans;
        for(vector<int>& q : queries){
            Ans.push_back(GetLength(q[0],q[1]));
        }
        return Ans;
    }
};