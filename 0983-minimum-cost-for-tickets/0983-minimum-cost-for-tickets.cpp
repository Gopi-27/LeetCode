class Solution {
public:
    int GetLowerBound(vector<int>& A,int low,int key){
        // index of first value > key
        int high = A.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(A[mid] <= key){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
    int rec(int level,vector<int>&days,vector<int>&costs){
        // pruning
        
        // basecase
        if(level >= days.size())return 0;
        // cachecheck

        // compute
        int ans = INT_MAX;
        // one 
        ans = min(ans,costs[0] + rec(level + 1,days,costs));
        // seven
        ans = min(ans,costs[1] + rec(GetLowerBound(days,level,days[level] + 6),days,costs));
        // thirty
        ans = min(ans,costs[2] + rec(GetLowerBound(days,level,days[level] + 29),days,costs));

        // save and return
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       return rec(0,days,costs);
    }
};