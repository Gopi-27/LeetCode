class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        double ans = 100;
        int n = nums.size();
        for(int i = 0; i < n/2; i++){
            double avg = (nums[i] + nums[n-i-1])/2.0;
                if(avg < ans)ans = avg;
        }
        return ans;
    }
};