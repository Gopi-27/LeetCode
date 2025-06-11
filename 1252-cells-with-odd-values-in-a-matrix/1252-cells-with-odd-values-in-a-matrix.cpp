class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int>Col(n);
        vector<int>Row(m);
        for(auto b : indices){
            Row[b[0]]++;
            Col[b[1]]++;
        }
        int ans = 0;
        int cnt = 0;
        for(int b : Col){
            if(b & 1){
                cnt++;
            }
        }
        for(int b : Row){
            if(b & 1){
                ans += n;
                ans -= cnt;
            }else{
                ans += cnt;
            }
        }
        return ans;

        
    }
};