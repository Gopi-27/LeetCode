class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mpp[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for(auto b : mpp){
            ans += ((b.second * (b.second - 1))/2);
        }
        return ans * 8;
    }
};