class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>mpp;
        for(auto b : nums)mpp[b++];
        int val = k;
        while(1){
            if(mpp.count(k))k += val;
            else return k;
        }
        return 0;
    }
};