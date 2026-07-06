class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = n;
        int r = -1;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]){
                l = min(i,l);
                r = max(i + 1,r);
            }
        }
        if(l > r)return 0;
        int mini = nums[l];
        int maxi = nums[l];
        for(int i = l; i <= r; i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        } 
        // cout << l << ' ' << r << endl;
        while(1){
            bool flag = 0;
            if(l > 0 && nums[l - 1] > mini){
                l--;
                maxi = max(maxi,nums[l]);
                flag = 1;
            } 
            if(r < n - 1 && nums[r + 1] < maxi){
                r++;
                mini = min(mini,nums[r]);
                flag = 1;
            }
            if(!flag)break;
        }
        // cout << l << " " << r << endl;
        return r - l + 1;

        // -110 -5 2 3 |4 -1|  -10 2 3 4
        //        -1       4

    }
};