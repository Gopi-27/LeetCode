class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int Ans = 0;
        int PrevCnt = 0;
        int CurCnt = 0;
        int zcnt = 1;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i])CurCnt++;
            else{
                Ans = max(Ans,PrevCnt + CurCnt);
                PrevCnt = CurCnt;
                CurCnt = 0;
            }
        }
        Ans = max(Ans,PrevCnt + CurCnt);
        return Ans == n ? n - 1: Ans;


    }
};