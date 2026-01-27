class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 1;
        while(i < n && nums[i] == nums[0])i++;
        if(i >= n)return ans;
        // ans++;
        bool flag = 0;
        if(nums[0] < nums[i])flag = 1;
        for(int j = i + 1; j < n; j++){
            if(flag){// up
                if(nums[j - 1] > nums[j]){
                    ans++;
                    flag = 0;
                }
            }else{
                if(nums[j - 1] < nums[j]){
                    ans++;
                    flag = 1;
                }
            }
        }
        return ans;
    }
};