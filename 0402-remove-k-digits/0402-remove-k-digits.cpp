class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        deque<char>dq;
        string ans = "";
        for(int i = 0; i < n; i++){
            while(!dq.empty() && dq.back() > nums[i])dq.pop_back();
            dq.push_back(nums[i]);
            if(i >= k){
                if(ans.size() == 0 && dq.front() == '0')dq.pop_front();
                else {
                    ans += dq.front();
                    dq.pop_front();
                }
            }
        }
        if(ans.size() == 0)return "0";
        return ans;
    }
};


// 143562219
// -------------
// 100000000
//  40000000
//   3000000
//    500000
//     60000
//      2000