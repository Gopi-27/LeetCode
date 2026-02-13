class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        map<int,vector<int>>mpp;
        for(int i = 0; i < groupSizes.size(); i++){
            mpp[groupSizes[i]].push_back(i);
        }
        for(auto b : mpp){
            int l = b.first;
            int n = b.second.size();
            for(int i = 0; i < n; i += l){
                vector<int>temp;
                for(int j = i; j < i + l; j++){
                    temp.push_back(b.second[j]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};