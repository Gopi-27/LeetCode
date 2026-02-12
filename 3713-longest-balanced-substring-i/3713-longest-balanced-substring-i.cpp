class Solution {
public:
    bool Valid(vector<int>& F,int key){
        for(int i = 0; i < 26; i++){
            if(F[i] == 0 || F[i] == key)continue;
            return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int>F(26);
            int maxi = 0;
            for(int j = i; j < n; j++){
                maxi = max(maxi,++F[s[j] - 'a']);
                if(Valid(F,maxi))ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};