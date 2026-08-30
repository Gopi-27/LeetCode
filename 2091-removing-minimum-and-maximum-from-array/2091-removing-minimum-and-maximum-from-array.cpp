class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int miniIdx = 0;
        int maxi = nums[0];
        int maxiIdx = 0;
        for(int i = 1; i < n; i++){
            if(maxi < nums[i]){
                maxi = nums[i];
                maxiIdx = i;
            }

            if(mini > nums[i]){
                mini = nums[i];
                miniIdx = i;
            }
        }

        if(miniIdx > maxiIdx)swap(miniIdx,maxiIdx);
        return min({miniIdx + 1 + n - maxiIdx,maxiIdx + 1,n - miniIdx});
    }
};