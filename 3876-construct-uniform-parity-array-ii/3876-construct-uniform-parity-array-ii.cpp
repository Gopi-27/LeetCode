class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        bool eflag = 0;
        bool oflag = 0;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0)eflag = 1;
            else{
               oflag = 1;
                mini = min(nums[i],mini);
            } 
        }
        if(eflag && !oflag)return true;
        if(oflag && !eflag)return true;
        if(!oflag)return false;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1)continue;
            if(mini > nums[i])return false;
        }
        return true;
    }
};