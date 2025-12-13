class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int last_idx = 0;
        for(int i = 0; i < arr.size(); i++){
            last_idx = max(last_idx,arr[i]);
            if(last_idx == i)ans++;
        }
        return ans;
    }
};