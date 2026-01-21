class Solution {
public:
    bool Valid(vector<int>& nums,int k,int key){
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += nums[i] / key;
            if(nums[i] % key == 0)cnt--;
        }
        return cnt <= k;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int low = 1;
        int high = 0;
        for(int i = 0; i < n; i++)high = max(high,nums[i]);
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Valid(nums,maxOperations,mid))high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

// 1 2 3 4 5 6 7 8 9
// 5    4 -> 1
// 3 2 2 2 -> 1 + 1 = 3
// 1 2      -> 1 = 4;

// 3 4

// 9 
// 3 6
//   3 3