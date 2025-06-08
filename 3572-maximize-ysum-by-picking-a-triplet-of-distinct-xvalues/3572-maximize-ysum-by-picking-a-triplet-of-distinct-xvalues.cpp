class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        map<int,int>mpp;
        int n = x.size();
        for(int i = 0; i < n; i++){
            if(mpp.count(x[i]) == 0)mpp[x[i]] = y[i];
            else mpp[x[i]] = max(mpp[x[i]],y[i]);
        }
        int size = mpp.size();
        if(size < 3)return -1;
        // get top 3 one right side elements
        vector<int>ans;
        for(auto b : mpp)ans.push_back(b.second);
        sort(ans.begin(),ans.end());
        return ans[size - 3] + ans[size - 2] + ans[size - 1];
          
    }
};