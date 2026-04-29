class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<int>LPref(n),TSuff(n);
        if(s[0] == 'L')LPref[0]++;
        if(s[n - 1] == 'T')TSuff[n - 1]++;
        for(int i = 1; i < n; i++){
            if(s[i] == 'L')LPref[i]++;
            LPref[i] += LPref[i - 1];
        }
        for(int i = n - 2; i >= 0; i--){
            if(s[i] == 'T')TSuff[i]++;
            TSuff[i] += TSuff[i + 1];
        }
        long long Lans = 0,Tans = 0;
        long long ans = 0;
        long long max_of_c = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'C'){
                Lans += 1ll * (LPref[i] + 1) * TSuff[i];
                Tans += 1ll * LPref[i] * (TSuff[i] + 1);
                ans += 1ll * LPref[i] * TSuff[i];
            }
            max_of_c = max(max_of_c,1ll * LPref[i] * TSuff[i]);
            
        }
        return max({Lans,Tans,ans + max_of_c});
    }
};