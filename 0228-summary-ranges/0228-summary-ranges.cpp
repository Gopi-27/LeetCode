class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string>ans;
        if(n <= 0)return ans;
        string t = "";
        t += to_string(nums[0]);
        if(n == 1)return {t};

        for(int i = 1; i < n; i++){
            if(nums[i - 1] + 1 == nums[i]){
                continue;
            }else{
                if(stoi(t) == nums[i - 1]){
                    ans.push_back(t);
                }else{
                    t += "->" + to_string(nums[i - 1]);
                    ans.push_back(t);
                }
                t = to_string(nums[i]);

            }
        }
        if(stoi(t) != nums[n -1])t += "->" + to_string(nums[n - 1]);
        ans.push_back(t);
        return ans;
    }
};