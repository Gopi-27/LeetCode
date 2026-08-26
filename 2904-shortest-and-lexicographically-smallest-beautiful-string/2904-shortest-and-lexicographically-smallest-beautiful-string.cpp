class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++)ans += '1';
        int len = INT_MAX;
        int l = 0, r = 0;
        while(l < n && s[l] == '0')l++;
        r = l;
        int cnt = 0;
        while(r < n && cnt < k){
            if(s[r] == '1')cnt++;
            r++;
        }
        if(cnt == k){
            len = min(len,r - l);
            ans = s.substr(l,len);
        }
        while(r < n){
            l++;
            while(l < n && s[l] == '0')l++;
            while(r < n && s[r] == '0')r++;
            if(r < n){
                r++;
                

                if(r - l == len){
                    ans = min(ans,s.substr(l,len));
                }else if(r - l < len){
                    ans = s.substr(l,r - l);
                }

                len = min(len,r - l);
            }
        }

        return (len == INT_MAX)? "" : ans;
    }
};

