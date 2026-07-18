class Solution {
public:
    int GCD(int a,int b){
        if(a == b)return a;
        if(a == 0)return b;
        if(b == 0)return a;
        if(a > b)return GCD(a % b, b);
        else return GCD(a,b % a);
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int min = nums[0];
        int max = nums[0];
        for(int i = 1; i < n; i++){
            if(min > nums[i])min = nums[i];
            if(max < nums[i])max = nums[i];

        }
        return GCD(min,max);
    }
};