class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>Ans(2);
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        for(int it : nums1)mpp1[it]++;
        for(int it : nums2)mpp2[it]++;
        for(auto b : mpp1){
            if(mpp2[b.first] == 0)Ans[0].push_back(b.first);
        }
        for(auto b : mpp2){
            if(mpp1[b.first] == 0)Ans[1].push_back(b.first);
        }
        return Ans;
    }
};