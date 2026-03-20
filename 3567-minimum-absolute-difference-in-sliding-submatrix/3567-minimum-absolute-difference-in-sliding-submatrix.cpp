class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>Ans;
        for(int i = 0; i <= n - k; i++){
            vector<int>temp;
            for(int j = 0; j <= m - k; j++){
                set<int>st;
                for(int ki = i; ki < i + k; ki++){
                    for(int kj = j; kj < j + k; kj++){
                        st.insert(grid[ki][kj]);
                    }
                }
                if(st.size() == 1)temp.push_back(0);
                else{
                    int prev = 0;
                    int val = INT_MAX;
                    int cnt = 0;
                    for(auto b : st){
                        if(cnt > 0)val = min(val,abs(prev - b));
                        prev = b;
                        cnt++;
                    }
                    temp.push_back(val);
                }
            }
            Ans.push_back(temp);
        }
        return Ans;
    }
};

// 0 1 2 3 4 
// 5 6 7 8 9
// 0 1 2 3 4 
// 5 6 7 8 9