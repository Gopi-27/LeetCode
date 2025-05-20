class Solution {
public:
    void GetSub(vector<int>& nums,int i,int n,vector<int>&ans,vector<vector<int>>& Res){
        if(i == n)return ;
        // picking
        ans.push_back(nums[i]);
        GetSub(nums,i + 1,n,ans,Res);
        Res.push_back(ans);
        // not piking;
        ans.pop_back();
        GetSub(nums,i + 1,n,ans,Res);

        // Res.push_back(ans);
        return ;
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> Res;
        vector<int>ans;
        Res.push_back(ans);
        GetSub(nums,0,nums.size(),ans,Res);
        return Res;
    }
};