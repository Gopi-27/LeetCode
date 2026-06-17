class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        long long sum = 0;
        for(int& v : piles){
            pq.push(v);
            sum += v;
        }
        while(k--){
            int val = pq.top();pq.pop();
            sum -= val/2;
            pq.push((val + 1)/2);
        }
        return sum;
        
    }
};