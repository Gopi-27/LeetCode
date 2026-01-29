class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        map<int,int>mpp;
        for(int i = 0; i < n; i++)mpp[tasks[i]]++;
        int ans = 0;
        for(auto b : mpp){
            int val = b.second;
            if(val % 3 == 0)ans += val/3;
            else if(val % 3 == 2)ans += (val/3) + 1;
            else {
                if(val == 1)return -1;
                ans += 2;
                val -= 4;
                ans += val/3;
            }

        }
        return ans;
    }
};