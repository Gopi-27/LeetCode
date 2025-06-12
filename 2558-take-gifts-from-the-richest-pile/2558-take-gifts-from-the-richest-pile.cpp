class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        long long ans = 0;
        int n = gifts.size();
        for(int i = 0; i < n; i++){
            ans += gifts[i];
            pq.push(gifts[i]);
        }
        while(k--){
            int max = pq.top();
            pq.pop();
            ans -= max;
            ans += sqrt(max);
            pq.push(sqrt(max));
        }
        return ans;
    }
};