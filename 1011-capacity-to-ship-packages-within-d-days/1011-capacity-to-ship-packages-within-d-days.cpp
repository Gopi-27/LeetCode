class Solution {
public:
    bool Check(vector<int>& weights,int days,int MaxCap){
        int n = weights.size();
        int parts = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(sum + weights[i] <= MaxCap)sum += weights[i];
            else {
                parts++;
                sum = weights[i];
            }
        }
        return parts <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int n = weights.size();
        int low = 0;
        for(int i = 0; i < n; i++){
            sum += weights[i];
            low = max(low,weights[i]);
        }
        // max(weights)
        int high = sum;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Check(weights,days,mid))high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};