class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int>mpp;
        for(int i = 0; i < n; i++)mpp[arr[i]]++;
        vector<int>A;
        for(auto b : mpp)A.push_back(b.second);
        sort(A.begin(),A.end(),greater<int>());
        int cnt = 0;
        int ans = 0;
        for(auto b : A){
            if(cnt >= n/2)return ans;
            cnt += b;
            ans++;
        }
        return ans;
    }
};