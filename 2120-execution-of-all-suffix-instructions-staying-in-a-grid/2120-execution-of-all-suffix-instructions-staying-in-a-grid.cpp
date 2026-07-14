class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int>Ans(m);
        for(int k = 0; k < m; k++){
            int i = startPos[0];
            int j = startPos[1];
            int idx = k;
            while(idx < m){
                if(s[idx] == 'U'){
                    if(i - 1 < 0)break;
                    i--;
                }else if(s[idx] == 'R'){
                    if(j + 1 >= n)break;
                    j++;
                }else if(s[idx] == 'D'){
                    if(i + 1 >= n)break;
                    i++;
                }else{// L
                    if(j - 1 < 0)break;
                    j--;
                }
                idx++;
            }
            // cout << idx << " ";
            Ans[k] = idx - k;
        }
        return Ans;
    }
};