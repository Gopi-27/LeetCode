class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum = (1LL * k * (k + 1))/2;
        int last = k;
        set<int>st;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        for(auto b : st){
            if(b <= last){
                sum -= b;
                sum += ++last;
            }
        }
        return sum;
    }

};