class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int,int>mpp;
        for(auto b : arr)mpp[b]++;
        set<int>st;
        for(auto b : mpp)st.insert(b.second);
        return st.size() == mpp.size();
    }
};