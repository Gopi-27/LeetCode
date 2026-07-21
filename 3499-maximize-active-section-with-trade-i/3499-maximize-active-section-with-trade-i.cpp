class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt = 0;
        char prev = '1';
        vector<int>A;
        int n = s.size();
        int active = 0;
        for(int i = 0; i < n; i++){
            if(prev == s[i])cnt++;
            else{
                A.push_back(cnt);
                prev = s[i];
                cnt = 1;
            }
            active += s[i] - '0';
        }
        A.push_back(cnt);
        if(s[n - 1] == '0')A.push_back(0);
        // for(int& a : A)cout << a << " ";
        // 1 0 1 0 1 0 1 0 1
        // 0 1 2 3 4 5 6 7 8 
        int ans = active;
        int m = A.size();
        for(int i = 2; i < m - 1; i += 2)ans = max(ans, active + A[i - 1] + A[i + 1]);
        return ans;
    }
};