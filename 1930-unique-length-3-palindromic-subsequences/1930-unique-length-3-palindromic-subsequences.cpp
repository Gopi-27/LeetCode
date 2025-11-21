class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<pair<int,int>>A(26,{n,-1});
        for(int i = 0; i < n; i++){
           A[s[i] - 'a'].first = min(A[s[i] - 'a'].first,i);
           A[s[i] - 'a'].second = max(A[s[i] - 'a'].second,i); 
        }
        int ans = 0;
        for(auto b : A){
            int mask = 0;
            for(int i = b.first + 1; i < b.second; i++){
                if(!(mask & (1 << (s[i] - 'a')))){
                    mask |= (1 << s[i] - 'a');
                    ans++;
                }
            }
        }
        return ans;
    }
};