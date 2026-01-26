class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>Win(1e5 + 1);
        vector<int>Los(1e5 + 1);
        for(vector<int>& m : matches){
            Win[m[0]]++;
            Los[m[1]]++;
        }
        vector<vector<int>>ans(2);
        for(int i = 0; i <= 1e5; i++){
            if(Los[i] == 0 && Win[i] > 0)ans[0].push_back(i);

            if(Los[i] == 1)ans[1].push_back(i);
        }
        return ans;

    }
};