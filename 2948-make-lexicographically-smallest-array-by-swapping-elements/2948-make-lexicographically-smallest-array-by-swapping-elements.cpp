class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>>A;
        for(int i = 0; i < n; i++)A.push_back({nums[i],i});
        sort(A.begin(),A.end());
        A.push_back({2e9,n});
        vector<int>Ele,Idx;
        for(int i = 0; i < n; i++){
            Ele.push_back(A[i].first);
            Idx.push_back(A[i].second);
            if(A[i + 1].first - A[i].first > limit){
                sort(Idx.begin(),Idx.end());
                int m = Idx.size();
                for(int j = 0; j < m; j++)nums[Idx[j]] = Ele[j];
                Ele.clear();
                Idx.clear();
            }
        }
        return nums;
    }
};