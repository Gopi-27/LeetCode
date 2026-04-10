class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<double,vector<int>>>A(n);
        for(int i = 0; i < n; i++){
            A[i].first = (double)sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            A[i].second = points[i];
        }
        sort(A.begin(),A.end());
        vector<vector<int>>Ans(k);
        for(int i = 0; i < k; i++){
            Ans[i] = A[i].second;
        }
        return Ans;
    }
};