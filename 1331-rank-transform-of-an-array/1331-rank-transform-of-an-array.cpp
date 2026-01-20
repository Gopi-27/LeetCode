class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mpp;
        int n = arr.size();
        for(int i = 0; i < n; i++)mpp[arr[i]]++;
        int rnk = 0;
        for(auto& b : mpp){
            b.second = ++rnk;
        }
        for(int i = 0; i < n; i++){
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};