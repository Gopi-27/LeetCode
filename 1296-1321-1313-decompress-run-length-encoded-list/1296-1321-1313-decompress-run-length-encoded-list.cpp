class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>Ans;
        for(int i = 0; i < nums.size(); i += 2){
            Ans.insert(Ans.end(),nums[i],nums[i + 1]);
        }
        return Ans;

    }
};