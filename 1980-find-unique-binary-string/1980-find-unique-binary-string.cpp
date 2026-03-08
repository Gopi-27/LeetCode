class Solution {
public:
    string GetStr(int i,int n){
        string s = "";
        while(i > 0){
            s += (char)((i % 2) + '0');
            i >>= 1;
        }
        while(s.size() < n)s += '0';
        reverse(s.begin(),s.end());
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            string ans = GetStr(i,n);
            if(find(nums.begin(),nums.end(),ans) == nums.end())return ans;
        }
        return "";
    }
};