class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            map<int,int>empp;
            map<int,int>ompp;
            for(int j = i; j < n; j++){
                if(nums[j] % 2 == 0)empp[nums[j]]++;
                else ompp[nums[j]]++;
                if(empp.size() == ompp.size())ans = max(ans,j - i + 1);
            }
        }
        return ans;
    }
};