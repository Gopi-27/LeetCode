class Solution {
public:
    int mod = 1e9 + 7;
    pair<int,int> Search(vector<int>& A,int key){
        int low = 0;
        int high = A.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(A[mid] <= key)low = mid + 1;
            else high = mid - 1;
        }
        return {low,A.size() - low};
    }
    int specialTriplets(vector<int>& nums) {
        map<int,vector<int>>mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++)mpp[nums[i]].push_back(i);
        int ans = 0;
        for(int i = 0; i < n; i++){
            pair<int,int>cnt = Search(mpp[nums[i] * 2],i);
            if(nums[i] == 0)cnt.first--;
            ans = (ans + ((1ll * cnt.first * cnt.second) % mod)) % mod;
        }
        return ans;
    }
};