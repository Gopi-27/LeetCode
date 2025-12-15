class Solution {
public:
    bool Check(vector<int>& quantities,int MaxPro,int n){
        long long req = 0;
        for(int & q : quantities){
            req += q/MaxPro;
            if(q % MaxPro != 0)req++;
        }
        return req <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = 1;
        for(int& q : quantities)high = max(high,q);
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Check(quantities,mid,n))high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};