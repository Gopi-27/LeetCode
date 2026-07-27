class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int cnt = 0;
        int end = -1;
        int n = points.size();
        for(int i = 0; i < n; i++){
            if(points[i][0] <= end)continue;
            cnt++;
            end = points[i][0] + w;
        }
        return cnt;
    }
};