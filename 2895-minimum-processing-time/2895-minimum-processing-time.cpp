class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end(),greater<int>());
        int n = processorTime.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans,processorTime[i] + tasks[i * 4]);
        }
        return ans;
        //      0    1   2   3   4 - > i
        // 
        //      0    4   8  12  16

        // 3
        // 3 + (1)4
        // 3 + (2)4
        
    }
};