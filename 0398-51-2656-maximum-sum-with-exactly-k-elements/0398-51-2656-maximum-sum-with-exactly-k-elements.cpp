class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max = 0;
        for(int i : nums){
            if(max < i)max = i;
        }
        return (k*(max + max + k - 1))/2;
    }
};