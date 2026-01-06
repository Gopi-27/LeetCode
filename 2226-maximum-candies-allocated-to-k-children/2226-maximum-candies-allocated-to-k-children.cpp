class Solution {
public:
    bool Allocate(vector<int>& candies,int c,long long k){
        if(c <= 0)return true;
        long long child = 0;
        for(int i = 0; i < candies.size(); i++)
            child += candies[i]/c;
        return child >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 0;
        int high = candies[0];
        for(int i = 1; i < candies.size(); i++)high = max(candies[i],high);
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Allocate(candies,mid,k))low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};