class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>InDeg(n);
        for(vector<int>& e : edges)
            InDeg[e[1]]++;
        int champ;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!InDeg[i]){
                champ = i;
                cnt++;
            }
        }
        if(cnt == 1)return champ;
        return -1;
    }
};