class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n % 2)return {};
        map<int,int>mpp;
        for(int i = 0; i < n; i++)mpp[changed[i]]++;
        vector<int>sol;
        for(auto b : mpp){
            if(b.second == 0)continue;
            if(b.second > mpp[2 * b.first])return {};
            mpp[2 * b.first] -= b.second;
            b.second = (b.first == 0) ? b.second/2 : b.second;
            for(int i = 0; i < b.second; i++)sol.push_back(b.first);

        }
        return sol;
    }
};