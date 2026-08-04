class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = 10000;
        int maxi = 0;
        map<int,int>mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        vector<int>Ans;
        for(int i = mini + 1; i < maxi; i++){
            if(mpp.count(i) == 0)Ans.push_back(i);
        }
        return Ans;
    }
};