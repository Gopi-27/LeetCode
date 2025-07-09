class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int n = nums.size();
        int sum = 0;
        while (i < n && i < k && nums[i] < 0){
            nums[i] = -nums[i];
            sum += nums[i++];
        }
        for(int j = i; j < n; j++)sum += nums[j];
        if(i == k){
            // k ended n reamains
            return sum;
        }else{
            // negatives are lessthan k
            k -= i;
            if(k % 2 == 0){
                return sum;
            }else{
                int min = nums[0];
                for(int i = 1; i < n; i++)if(nums[i] < min)min = nums[i];
                sum -= (min + min);
                return sum;
            }
        }

    }
};