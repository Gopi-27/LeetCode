class Solution {
public:
    int minimumPushes(string word) {
        vector<int>Frr(26);
        for(char& ch : word)Frr[ch - 'a']++;
        vector<int>A;
        for(int& f : Frr)if(f)A.push_back(f);
        sort(A.begin(),A.end(),greater<int>());
        int fact = 0;
        int ans = 0;
        for(int i = 0; i < A.size(); i++){
            if(i % 8 == 0)fact++;
            ans += A[i] * fact;
        }
        return ans;
    }
};