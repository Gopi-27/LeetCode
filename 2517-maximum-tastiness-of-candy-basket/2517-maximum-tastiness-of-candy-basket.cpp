class Solution {
public:
    int GetIdx(vector<int>&price,int key,int start){
        int low = start;
        int high = price.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(price[mid] >= key)high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
    bool Possible(vector<int>& price,int key,int k){
        int cnt = 1;
        int ele = price[0];
        int idx = 0;
        int n = price.size();
        while(cnt < k){
            idx = GetIdx(price,price[idx] + key,idx + 1);
            if(idx >= n)break;
            cnt++;
        }
        return cnt >= k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n = price.size();
        int low = 0;
        int high = price[n - 1] - price[0];
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Possible(price,mid,k))low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};