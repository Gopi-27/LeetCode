class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int,pair<int,int>>mpp;
        int maxi = 0;
        int ans = 0;
        for(auto b : nums){
            if(mpp.count(b % space)){
                mpp[b % space].first++;
                mpp[b % space].second = min(mpp[b % space].second,b);
            }else{
                mpp[b % space].first++;
                mpp[b % space].second = b;
            }

            maxi = max(maxi, mpp[b % space].first);
            ans = max(ans,b);
        }
        for(auto b : mpp){
            if(b.second.first == maxi)ans = min(ans,b.second.second);
        }    
        return ans;    
    }
};