class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!nums[i])k--;
            while(k < 0){
                if(!nums[l])k++;
                l++;
            }
            if(l <= i)ans = max(ans,i - l + 1);
        }
        return ans;
    }
};