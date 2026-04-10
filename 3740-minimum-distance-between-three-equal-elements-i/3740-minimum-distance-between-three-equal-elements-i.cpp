class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }
        bool flag = 0;
        int ans = INT_MAX;
        for(auto b : mpp){
            int len = b.second.size();
            if(len >= 3){
                flag = 1;
                for(int i = 0; i < len - 2; i++)
                    ans = min(ans, 2 * (b.second[i + 2] - b.second[i]));
            }  
        }
        if(!flag)
            return -1;
        return ans;
    }
};
    