class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.size();
        int m = t.size();
        if(n != m)return false;
        vector<int>Avail(27);
        Avail[0] = n;
        for(int i = 1; i <= 26; i++)
            Avail[i] = (k + (26 - i))/26;
        for(int i = 0; i < n; i++){
            int req = t[i] - s[i]; 
            if(req < 0)req = 26 + req;
            if(!Avail[req])return false;
            Avail[req]--;        
        }
        return true;
    }
};