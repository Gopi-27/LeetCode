class Solution {
public:
    bool CanMake(vector<int>&bloomDay,int m,int k,int key){
        int n = bloomDay.size();
        int bouqs = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= key)cnt++;
            else{
                bouqs += cnt/k;
                cnt = 0;
            }
        }
        bouqs += cnt/k;
        return bouqs >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1ll * m * k > n)return -1;
        int low = 1;
        int high = 1e9;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(CanMake(bloomDay,m,k,mid))high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};