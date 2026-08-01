class Solution {
public:
    pair<int,int> rec(int l,int r,vector<int>& nums){
        if(l > r)return {0,0};
        pair<int,int> ans;
        pair<int,int> s1 = rec(l + 1,r,nums);
        pair<int,int> s2 = rec(l,r - 1,nums);
        if(nums[l] + s1.second > nums[r] + s2.second)ans = {nums[l] + s1.second, s1.first};
        else ans = {nums[r] + s2.second, s2.first};
        return ans;        
    }
    bool predictTheWinner(vector<int>& nums) {
        pair<int,int> p = rec(0,nums.size() - 1,nums);
        return p.first >= p.second;
    }
};