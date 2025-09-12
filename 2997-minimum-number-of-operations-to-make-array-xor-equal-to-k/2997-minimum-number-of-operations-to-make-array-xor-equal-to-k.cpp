class Solution {
public:
    int GetAns(int n){
        int cnt = 0;
        while(n > 0){
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }
    int minOperations(vector<int>& nums, int k) {
        int val = 0;
        for(auto it : nums)val ^= it;
        val ^= k;
        return GetAns(val);
       
    }
};