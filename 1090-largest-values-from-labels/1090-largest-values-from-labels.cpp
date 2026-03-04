class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>>A;
        int n = values.size();
        for(int i = 0; i < n; i++)A.push_back({values[i],labels[i]});
        sort(A.begin(),A.end(),greater<pair<int,int>>());
        map<int,int>mpp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(numWanted == 0)return ans;
            if(mpp[A[i].second] >= useLimit)continue;
            ans += A[i].first;
            mpp[A[i].second]++;
            numWanted--;
        }
        return ans;
    }
};