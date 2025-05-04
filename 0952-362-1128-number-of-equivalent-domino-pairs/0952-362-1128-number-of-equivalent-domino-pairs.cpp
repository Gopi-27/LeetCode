class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        for(int i = 0; i < n; i++){
            if(dominoes[i][0] > dominoes[i][1]){
                swap(dominoes[i][0],dominoes[i][1]);
            }
        }
        sort(dominoes.begin(),dominoes.end());
        int cnt = 1;
        int Ans = 0;
        for(int i = 1; i < n; i++){
            if(dominoes[i - 1][0] == dominoes[i][0] && dominoes[i - 1][1] == dominoes[i][1]){
                cnt++;
            }else{
                Ans += ((cnt) * (cnt - 1)) / 2;
                cnt = 1;
            }

        }
        Ans += ((cnt) * (cnt - 1)) / 2;
        return Ans;
        
    }
};