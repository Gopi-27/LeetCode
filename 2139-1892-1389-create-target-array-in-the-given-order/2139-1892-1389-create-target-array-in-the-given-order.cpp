class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int>Tar;
        for(int i = 0; i < nums.size(); i++){
            Tar.insert(Tar.begin() + index[i],nums[i]);
        }
        return Tar;
    }
};