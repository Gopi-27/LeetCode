class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>A;
        int n = profit.size();
        for(int i = 0; i < n; i++)A.push_back({profit[i],difficulty[i]});
        sort(A.begin(),A.end(),greater<pair<int,int>>());
        sort(worker.begin(),worker.end(),greater<int>());
        int ans = 0;
        int idx = 0;
        int m = worker.size();
        for(int i = 0; i < n; i++){
            while(idx < m && worker[idx] >= A[i].second){
                ans += A[i].first;
                idx++;
            }
        }
        return ans;

    }
};