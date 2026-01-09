class Solution {
public:
    bool Possible(vector<int>& nums,int k,int key){
        int cnt = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > key){
                sum = nums[i];
                cnt++;
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi = 0;
        int high = 0;
        for(int i = 0; i < nums.size(); i++){
            maxi = max(nums[i],maxi);
            high += nums[i];
        }
        int low = maxi;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Possible(nums,k,mid))high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};