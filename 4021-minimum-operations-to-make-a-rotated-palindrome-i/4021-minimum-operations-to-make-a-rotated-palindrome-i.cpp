class Solution {
public:
    int MakePalindrome(string& s,int l,int r){
        int oper = 0;
        while(l < r){
            if(s[l] != s[r]){
                int maxi = max(s[l],s[r]) - 'a';
                int mini = min(s[l],s[r]) - 'a';
                oper += min(maxi - mini,26 - maxi + mini); 
            }
            l++;
            r--;
        }
        return oper;
    }
    int minOperations(string s) {
        int n = s.size();
        s += s;
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans, i + MakePalindrome(s,i,i + n - 1));
        }
        return ans;
    }
};