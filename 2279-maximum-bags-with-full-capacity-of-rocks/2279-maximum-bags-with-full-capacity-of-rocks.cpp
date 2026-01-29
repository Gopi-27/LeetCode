class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        vector<int>Need(n);
        for(int i = 0; i < n; i++){
            Need[i] = capacity[i] - rocks[i];
        }
        sort(Need.begin(),Need.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(additionalRocks - Need[i] >= 0){
                additionalRocks -= Need[i];
                ans++;
            }else return ans;
        }
        return ans;
    }
};