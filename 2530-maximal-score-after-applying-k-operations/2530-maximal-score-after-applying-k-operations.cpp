class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int& b : nums)pq.push(b);
        long long ans = 0;
        while(k--){
            int val = pq.top();pq.pop();
            ans += val;
            pq.push((val + 2)/3);
        }
        return ans;
    }
};