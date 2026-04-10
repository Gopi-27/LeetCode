class Solution {
public:
    int CountBits(int n){
        int cnt = 0;
        while(n > 0){
            if(n & 1)cnt++;
            n >>= 1;
        }
        return cnt;
    }
    
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>A(n);
        for(int i = 0; i < n; i++){
            A[i].first = nums[i];
            A[i].second = CountBits(nums[i]);
        }
        vector<pair<int,int>>MinMax;
        int mini = A[0].first;
        int maxi = mini;
        int wind = A[0].second;
        for(int i = 0; i < n; i++){
            if(A[i].second != wind){
                MinMax.push_back({mini,maxi});
                mini = A[i].first;
                maxi = mini;
                wind = A[i].second;
            }else{
                mini = min(mini,A[i].first);
                maxi = max(maxi,A[i].first);
            }
        }
        MinMax.push_back({mini,maxi});
        for(int i = 1; i < MinMax.size(); i++){
            if(MinMax[i - 1].second > MinMax[i].first)return false;
        }
        return true;
    }
};