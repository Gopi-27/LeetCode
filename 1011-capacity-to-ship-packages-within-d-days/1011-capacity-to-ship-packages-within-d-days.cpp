class Solution {
public:
    // bool Check(vector<int>& weights,int days,int MaxCap){
    //     int n = weights.size();
    //     int parts = 1;
    //     int sum = 0;
    //     for(int i = 0; i < n; i++){
    //         if(sum + weights[i] <= MaxCap)sum += weights[i];
    //         else {
    //             parts++;
    //             sum = weights[i];
    //         }
    //     }
    //     return parts <= days;
    // }
    // int shipWithinDays(vector<int>& weights, int days) {
    //     int sum = 0;
    //     int n = weights.size();
    //     int low = 0;
    //     for(int i = 0; i < n; i++){
    //         sum += weights[i];
    //         low = max(low,weights[i]);
    //     }
    //     // max(weights)
    //     int high = sum;
    //     while(low <= high){
    //         int mid = (low + high) >> 1;
    //         if(Check(weights,days,mid))high = mid - 1;
    //         else low = mid + 1;
    //     }
    //     return low;
    // O(n * log(sum(weights)));
    //          |
    //          V
    //  O(days * log(n) * log(sum(weights)));


    int SepWindow(vector<int>&PrefSum,int start,int rmvSum,int MaxCap){
        int low = start;
        int high = PrefSum.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            int sum = PrefSum[mid] - rmvSum;
            if(sum <= MaxCap)low = mid + 1;
            else high = mid - 1;
        }
        return low;
        // next start;
    }
    bool Check(vector<int>& PrefSum,int days,int MaxCap){
        int parts = 0;
        int start = 0;
        int rmvSum = 0;
        while(start != PrefSum.size()){
            start = SepWindow(PrefSum,start,rmvSum,MaxCap);
            rmvSum = PrefSum[start - 1];
            parts++;
        }
        return parts <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        vector<int>PrefSum;
        PrefSum.reserve(n);
        int sum = 0;
        int low = 0;
        for(int i = 0; i < n; i++){
            sum += weights[i];
            PrefSum.emplace_back(sum);
            low = max(low,weights[i]);
        }
        int high = sum;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(Check(PrefSum,days,mid))high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};