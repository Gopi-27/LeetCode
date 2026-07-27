class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        set<vector<int>>st;
        for(vector<int>& p : points)st.insert(p);
        int ans = INT_MAX;
        int n = points.size();
        for(int i = 0; i < n; i++){
            int x1 = points[i][0];
            int small = points[i][1];
            for(int j = i + 1; j < n && points[j][0] == x1; j++){
                int large = points[j][1];
                for(int k = j + 1; k < n; k++){
                    if(points[k][1] == small){
                        int x = points[k][0];
                        if(st.count({x,large}))ans = min(ans,(large - small) * (x - x1));
                    }
                }
            }
        }
        if(ans == INT_MAX)return 0;
        return ans;
    }
};