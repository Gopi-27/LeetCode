class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i = 0;
        int n = nums.size();
        while(i < n){
            if((nums[i + 2] - nums[i]) > k)return{};
            ans.push_back({nums[i],nums[i + 1],nums[i + 2]});
            i += 3;
        }





        for(auto b : ans)cout << b[0] << b[1] << " ";
        return ans;
    }
};