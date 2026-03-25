class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int>Diff(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            Diff[i] = reward2[i] - reward1[i];
            ans += reward2[i];
        }
        sort(Diff.begin(),Diff.end());
        for(int i = 0; i < k; i++)ans -= Diff[i];
        // for(int i = k; i < n; i++)ans += Diff[i];
        return ans;
    }
};

// k = 2
// 1 1 3 4
// 4 4 1 1

// 3 3 -2 -3
