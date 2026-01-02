class Solution {
public:
    int GetNext(vector<int>& nums,int i){
        if(nums[i] >= 1000)return nums.size();
        int key = nums[i] * nums[i];
        int low = i + 1;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] == key)return mid;
            else if(nums[mid] < key)low = mid + 1;
            else high = mid - 1;
        }
        return nums.size();

    }
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>Dp(n + 1);
        int maxi = 1;
        for(int i = n - 1; i >= 0; i--){
            Dp[i] = 1 + Dp[GetNext(nums,i)];
            maxi = max(maxi,Dp[i]);
        }
        
        return (maxi > 1)? maxi : -1;
    }
};