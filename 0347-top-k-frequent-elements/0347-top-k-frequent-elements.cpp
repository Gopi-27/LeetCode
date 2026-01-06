class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int& b : nums)mpp[b]++;
        priority_queue<pair<int,int>>pq;
        for(pair<int,int>b : mpp)pq.push({b.second,b.first});
        vector<int>ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};