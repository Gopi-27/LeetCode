class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int b : nums)mpp[b]++;
        int max = 1;
        int cnt = 0;
        for(auto b : mpp){
            if(b.second > max){
                cnt = 1;
                max = b.second;
            }else if(b.second == max)cnt++;
        }
        return max * cnt;
    }
};