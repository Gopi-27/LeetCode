class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        int curr = arr[0];
        for(int i = 1; i < n; i++){
            if(arr[i] < curr)cnt++;
            else{
                curr = arr[i];
                cnt = 1;
            }
            if(cnt == k)return curr;
        }
        return curr;
    }
};