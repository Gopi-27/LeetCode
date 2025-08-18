class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        int val = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == val){
                continue;
            }else{
                cnt++;
                val = nums[i];
            }
        }
        return cnt;
    }
};