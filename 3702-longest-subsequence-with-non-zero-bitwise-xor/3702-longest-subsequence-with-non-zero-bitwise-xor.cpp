class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int gor = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        bool onlyzero = true;;
        for(int i = 0; i < n - 1; i++){
            gor ^= nums[i];
            if(nums[i])onlyzero = false;
        }

        if(nums[n - 1])onlyzero = false;

        if(onlyzero)return 0;
        
        if(gor == nums[n - 1]){
            return n - 1;
        }else return n;
        
    }
};