bool comp(vector<int>& A,vector<int>& B){
    if(A[1] < B[1])return true;
    if(A[1] > B[1])return false;
    return A[0] < B[0];
}
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int prev = intervals[0][1] - 1;
        int curr = intervals[0][1];
        int n = intervals.size();
        int cnt = 2;
        for(int i = 1; i < n; i++){
            if(prev >= intervals[i][0]){
                continue;
            }else if(curr >= intervals[i][0]){
                cnt++;
                if(curr == intervals[i][1])prev = intervals[i][1] - 1;
                else prev = curr;
                curr = intervals[i][1];

            }else{
                cnt += 2;
                prev = intervals[i][1] - 1;
                curr = intervals[i][1];
            }
        }
        return cnt;
    }
};