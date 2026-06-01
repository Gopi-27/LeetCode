class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size() + 1;
        vector<long long>Cnt(n);
        for(int i = 0; i < n - 1; i++)Cnt[edges[i]] += i;
        long long maxi = 0;
        int vertex = -1;
        for(int i = 0; i < n; i++){
            if(Cnt[i] > maxi){
                maxi = Cnt[i];
                vertex = i;
            }
        }
        return vertex;
    }
};