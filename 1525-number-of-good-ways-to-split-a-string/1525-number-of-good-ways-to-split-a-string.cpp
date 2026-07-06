class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        int n = s.size();
        vector<int>Suff(26),Pref(26);
        int scnt = 0;
        for(int i = n - 1; i >= 0; i--){
            if(!Suff[s[i] - 'a'])scnt++;
            Suff[s[i] - 'a']++;
        }
        int pcnt = 0;
        for(int i = 0; i < n - 1; i++){
            if(!Pref[s[i] - 'a'])pcnt++;
            Pref[s[i] - 'a']++;

            if(Suff[s[i] - 'a'] == 1)scnt--;
            Suff[s[i] - 'a']--;

            if(pcnt == scnt)ans++;
        }
        return ans;
    }
};