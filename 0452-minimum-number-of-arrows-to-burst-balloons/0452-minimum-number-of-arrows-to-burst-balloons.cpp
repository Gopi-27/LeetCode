bool comp(vector<int>& a,vector<int>& b){
    if(a[1] < b[1])return true;
    if(a[1] > b[1])return false;
    return a[0] < b[0];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),comp);
        int cnt = 0;
        int i = 0;
        while(i < n){
            cnt++;
            int key = points[i][1];
            while(i < n && key >= points[i][0] && key <= points[i][1])i++;
        }
        return cnt;
    }
};