class Solution {
public:
    void GetAns(vector<int>& A,int idx,int cur,int & ans){
        if(idx == A.size()){
            ans += cur;
            return ;
        }
        // not pick;
        GetAns(A,idx + 1,cur,ans);
        // pick;
        GetAns(A,idx + 1,cur ^ A[idx],ans);
        return ;
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        GetAns(nums,0,0,ans);
        return ans;
    }
};