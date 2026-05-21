class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>>Ans(2,vector<int>(n));
        vector<int>Idx;
        for(int i = 0; i < n; i++){
            if(colsum[i] == 2){
                if(!upper || !lower)return {};
                Ans[0][i] = 1;
                Ans[1][i] = 1;
                upper--;
                lower--;
            }else if(colsum[i] == 1){
                Idx.push_back(i);
            }
        }
        for(int& i : Idx){
            if(upper){
                Ans[0][i] = 1;
                upper--;
            }else if(lower){
                Ans[1][i] = 1;
                lower--;
            }else return {}; 
        }
        if(upper || lower)return {};
        return Ans;
    }
};