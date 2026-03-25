class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        vector<pair<int,int>>PrefMax(n),PrefMin(n);
        vector<pair<int,int>>SuffMax(n),SuffMin(n);
        PrefMax[0] = {nums[0],0};
        PrefMin[0] = {nums[0],0};
        for(int i = 1; i < n; i++){
            if(PrefMax[i - 1].first >= nums[i])PrefMax[i] = PrefMax[i - 1];
            else PrefMax[i] = {nums[i],i};
            
            if(PrefMin[i - 1].first <= nums[i])PrefMin[i] = PrefMin[i - 1];
            else PrefMin[i] = {nums[i],i}; 
        }
        SuffMax[n - 1] = {nums[n - 1], n - 1};
        SuffMin[n - 1] = {nums[n - 1], n - 1};
        for(int i = n - 2; i >= 0; i--){
            if(SuffMax[i + 1].first >= nums[i])SuffMax[i] = SuffMax[i + 1];
            else SuffMax[i] = {nums[i],i};

            if(SuffMin[i + 1].first <= nums[i])SuffMin[i] = SuffMin[i + 1];
            else SuffMin[i] = {nums[i],i};            
        }

        for(int i = 0; i < n - indexDifference; i++){
            if(abs(PrefMax[i].first - SuffMin[i + indexDifference].first) >= valueDifference)
                return {PrefMax[i].second,SuffMin[i + indexDifference].second};
            if(abs(PrefMin[i].first - SuffMax[i + indexDifference].first) >= valueDifference)
                return {PrefMin[i].second,SuffMax[i + indexDifference].second};
        }
        return {-1,-1};
    }
};