class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        map<int,int>mpp;
        for(int i = 0; i < n; i++)mpp[points[i][1]]++;
        long long cnt = 0;
        int ans = 0;
        for(auto b : mpp){
            long long sum = (1ll * b.second * (b.second - 1))/2;
            ans = (ans + (1ll * cnt * sum)) % 1000000007;
            cnt += (b.second * (b.second - 1))/2;
        }
        return ans; 
    }
};