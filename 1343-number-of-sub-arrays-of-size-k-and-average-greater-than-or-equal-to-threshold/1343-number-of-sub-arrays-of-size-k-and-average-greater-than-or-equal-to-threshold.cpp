class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        double avg = 0;
        double sum = 0;
        int ans = 0;
        for(int i = 0; i < k; i++)sum += arr[i];
        avg = sum / k;
        if(avg >= threshold)ans++;
        for(int i = k; i < arr.size(); i++){
            sum += arr[i];
            sum -= arr[i - k];
            avg = sum / k;
            if(avg >= threshold)ans++;
        }
        return ans;
    }
};