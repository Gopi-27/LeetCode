class Solution {
public:
    bool Possible(int key,vector<int>& nums){
        int n = nums.size();
        long long rem = 0;
        for(int i = n - 1; i >= 0; i--){
            rem += max(0,nums[i] - key);
            int req = max(0,key - nums[i]);
            if(rem >= req)rem -= req;
            else rem = 0;
        }
        return rem == 0;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0; i < n; i++)maxi = max(maxi,nums[i]);
        int low = 0;
        int high = maxi;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Possible(mid,nums))high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};