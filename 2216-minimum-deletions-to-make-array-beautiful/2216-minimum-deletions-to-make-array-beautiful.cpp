class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(idx % 2 == 0){
                if(i == n - 1)continue;
                if(nums[i] != nums[i + 1])idx++;
            }else idx++;
        }
        return n - idx;
    }
};