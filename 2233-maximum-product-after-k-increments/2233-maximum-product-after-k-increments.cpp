class Solution {
public:
    int mod = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto b : nums)pq.push(-b);
        while(k--){
            int val = pq.top();pq.pop();
            val--;
            pq.push(val);
        }
        long long ans = 1;
        while(!pq.empty()){
            ans *= -pq.top();pq.pop();
            ans %= mod;
        }
        return ans;
    }
};