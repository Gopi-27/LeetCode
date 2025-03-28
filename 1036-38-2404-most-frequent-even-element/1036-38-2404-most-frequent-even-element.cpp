class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mpp;
        for(auto b : nums){
            if(b % 2 == 0)mpp[b]++;
        }
        int max = -1;
        int frr = 0;
        for(auto i : mpp){
            if(frr < i.second){
                max = i.first;
                frr = i.second;
            }
        }
        return max;
    }
};