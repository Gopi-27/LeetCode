class Solution {
public:
    int n;
    vector<int>Bit;
    void Update(int idx){
        while(idx <= n){
            Bit[idx]++;
            idx += idx & (-idx);
        }
    }
    int Query(int idx){
        int ans = 0;
        while(idx > 0){
            ans += Bit[idx];
            idx -= idx & (-idx);
        }
        return ans;
    }
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        this->n = n;
        Bit.resize(n + 1);
        long lcnt = 0;
        long gcnt = 0; 
        Update(nums[n - 1] + 1);      
        for(int i = n - 2; i >= 0; i--){
            Update(nums[i] + 1);
            lcnt += (nums[i] > nums[i + 1]) ? 1 : 0;
            gcnt += Query(nums[i]);
        }
        return lcnt == gcnt;
    }
};