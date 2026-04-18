class Solution {
public:
    bool Valid(vector<int>& nums,int k,int target){
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < k; i++)sum += nums[i];
        if(sum >= target)return true;
        for(int i = k; i < n; i++){
            sum -= nums[i - k];
            sum += nums[i];
            if(sum >= target)return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Valid(nums,mid,target))high = mid - 1;
            else low = mid + 1;
        }
        return (low > n) ? 0 : low;
    }
};