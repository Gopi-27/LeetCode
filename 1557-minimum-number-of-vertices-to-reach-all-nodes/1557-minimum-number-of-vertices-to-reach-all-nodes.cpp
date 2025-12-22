class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>InDeg(n);
        for(auto e : edges)
            InDeg[e[1]]++;
        vector<int>ans;
        for(int i = 0; i < n; i++)if(!InDeg[i])ans.push_back(i);
        return ans;
    }
};