class Solution {
public:
    bool isValid(int maxi,vector<int>& Diff,int p){
        int n = Diff.size();
        int cnt = 0;
        int i = 0;
        while(i < n){
            if(Diff[i] <= maxi){
                cnt++;i++;
            }
            i++;
        }
        // cout << cnt << " => ";
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        if(n == 1)return 0;
        sort(nums.begin(),nums.end());
        vector<int>Diff(n - 1);
        for(int i = 0; i < n - 1; i++)Diff[i] = nums[i + 1] - nums[i];
        int low = 0; 
        int high = nums[n - 1] - nums[0];
        // cout << low << " => " << high;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(isValid(mid,Diff,p))high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};