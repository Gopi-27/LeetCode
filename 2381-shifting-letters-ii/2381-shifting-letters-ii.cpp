class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>pref(n);
        for(vector<int>& v : shifts){
            int start = v[0];
            int end = v[1];
            int dir = v[2];
            if(dir){
                pref[start]++;
                if(end + 1 < n)pref[end + 1]--;
            }else{
                pref[start]--;
                if(end + 1 < n)pref[end + 1]++;
            }
        }
        for(int i = 1; i < n; i++)pref[i] = (pref[i] + pref[i - 1]) % 26;
        for(int i = 0; i < n; i++){
            int val = (s[i] - 'a' + pref[i]) % 26;
            s[i] = ('a' + val);
        }
        return s;        
    }
};