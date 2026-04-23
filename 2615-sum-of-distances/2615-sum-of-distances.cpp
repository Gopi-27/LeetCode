class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long>left(n),right(n);
        map<int,pair<int,int>>mpp;
        for(int i = 0; i < n; i++){
            if(mpp.count(nums[i])){
                int diff = i - mpp[nums[i]].first;
                int cnt = mpp[nums[i]].second;
                left[i] = left[mpp[nums[i]].first] + (1ll * diff * cnt);
            }
            mpp[nums[i]] = {i,mpp[nums[i]].second + 1};
        }
        mpp.clear();
        for(int i = n - 1; i >= 0; i--){
            if(mpp.count(nums[i])){
                int diff = mpp[nums[i]].first - i;
                int cnt = mpp[nums[i]].second;
                right[i] = right[mpp[nums[i]].first] + (1ll * diff * cnt);
            }
            mpp[nums[i]] = {i,mpp[nums[i]].second + 1};
            left[i] += right[i];
        }
        return left;
    }
};