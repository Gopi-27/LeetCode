class Solution {
public:
    void GetSub(vector<int>& nums,int n,int idx,int target,int & cnt,int cur){
        if(idx == n){
            if(cur == target)cnt++;
            return;
        }
        //pick
        GetSub(nums,n,idx + 1,target,cnt,cur | nums[idx]);
        // non pick
        GetSub(nums,n,idx + 1,target,cnt,cur);

    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i = 0; i < n; i++)target |= nums[i];
        int cnt = 0;
        int cur = 0;
        GetSub(nums,n,0,target,cnt,cur);
        return cnt;        
    }
};