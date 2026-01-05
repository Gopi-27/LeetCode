class Solution {
public:
    bool Possible(vector<int>& piles,int h,int k){
        long long req = 0;
        for(int i = 0; i < piles.size(); i++){
            req += piles[i]/k;
            if(piles[i] % k)req++;
        }
        return req <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = piles[0];
        for(int i = 0; i < piles.size(); i++)high = max(high,piles[i]);
        while(low <= high){
            int mid = low + ((high - low)/2);

            if(Possible(piles,h,mid))high = mid - 1;
            else low = mid + 1;
        }
        return high + 1;

    }
};