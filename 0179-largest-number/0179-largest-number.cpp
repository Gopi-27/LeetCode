bool comp(string& a,string& b){
    string s = a + b;
    string p = b + a;
    for(int i = 0; i < s.size(); i++){
        if(s[i] > p[i])return 1;
        else if(s[i] < p[i])return 0;
    }
    return 1;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string>arr;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!nums[i]){
                cnt++;
                continue;
            }
            string str = "";
            int m = nums[i];
            while(m > 0){
                int rem = m % 10;
                str = (char)('0' + rem) + str;
                m /= 10;
            }
            arr.push_back(str);
        }
        sort(arr.begin(),arr.end(),comp);
        string ans = "";
        for(int i = 0; i < arr.size(); i++)ans += arr[i];
        if(!ans.size()){
            return "0";
        }else{
            for(int i = 0;  i < cnt; i++)ans += '0';
        }
        return ans;
    }
};