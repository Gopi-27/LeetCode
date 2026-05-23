class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        while(i < n && nums[i - 1] <= nums[i])i++;
        if(i >= n)return true;
        cout << i << endl;
        int start = nums[0];
        if(nums[i] > start)return false;
        i++;
        cout << i << endl;
        while(i < n && nums[i] <= start && nums[i - 1] <= nums[i])i++;
        if(i >= n)return true;
        return false;
    }
};