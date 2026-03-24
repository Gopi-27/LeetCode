class Solution {
public:
    int FindLen(string& s,int k){
        int n = s.size();
        int len = INT_MAX;
        int l = 0, r = 0;
        while(l < n && s[l] == '0')l++;
        r = l;
        int cnt = 0;
        while(r < n && cnt < k){
            if(s[r] == '1')cnt++;
            r++;
        }
        if(cnt == k)len = min(len,r - l);
        while(r < n){
            l++;
            while(l < n && s[l] == '0')l++;
            while(r < n && s[r] == '0')r++;
            if(r < n){
                r++;
                len = min(len,r - l);
            }
        }

        return (len == INT_MAX)? -1 : len;
    }
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int len = FindLen(s,k);
        if(len == -1)return "";
        string ans = "";
        for(int i = 0; i < len; i++)ans += '1';
        int cnt = 0;
        for(int i = 0; i < len; i++)if(s[i] == '1')cnt++;
        if(cnt == k)ans = min(ans,s.substr(0,len));
        for(int i = len; i < n; i++){
            if(s[i] == '1')cnt++;
            if(s[i - len] == '1')cnt--;

            if(cnt == k){
                ans = min(ans,s.substr(i - len + 1,i + 1));
            }
        }
        return ans;
    }
};