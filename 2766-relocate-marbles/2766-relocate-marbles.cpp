class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int>mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(int i = 0; i < moveFrom.size(); i++){
            mpp.erase(moveFrom[i]);
            mpp[moveTo[i]] = 1;
        }
        vector<int>ans;
        for(auto b : mpp){
            ans.push_back(b.first);
        }
        return ans;
    }
};