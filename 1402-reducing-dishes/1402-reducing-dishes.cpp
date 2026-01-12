class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int ans = 0;
        int n = sat.size();
        vector<int>suff(n + 1);
        for(int i = n - 1; i >= 0; i--)
            suff[i] = sat[i] + suff[i + 1];
        
        for(int i = n - 1; i >= 0; i--){
            int val = sat[i];
            if(val + suff[i + 1] >= 0)ans += val + suff[i + 1];
            else break;
        }
        return ans;

        

    }
};